/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_cmdline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:24:34 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/20 19:35:46 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "minishell_parsing.h"
#include "minishell_def.h"
#include "libft.h"

static int	check_operators(char *ptr);
static void	set_escape_mode(t_escape *escape, char c);

/*
	DESCRIPTION
	The dup_cmdline() add a space character before and after
	each operator or parenthesis if they are are not already prefixed
	or suffixed by a whitespace character. The resulting string is
	attached to the string pointed by ptr. Memory for the new string
	is obtained with malloc(), and can be freed with free().
	
	RETURN VALUE
	The dup_cmdline() function return 0.
	On error, dup_cmdline() return -1 and the string pointed by ptr
	is set to NULL.
*/

int	dup_cmdline(char *cmdline, char **ptr)
{
	int			status;
	t_vector	vector;
	t_escape	escape;
	int			i;

	status = ft_vector_init(&vector, sizeof(char));
	init_escape(&escape);
	i = 0;
	while (status == SUCCESS && cmdline[i])
	{
		status = ft_vector_add(&vector, cmdline + i);
		if (cmdline[i] == '\'' || cmdline[i] == '\"')
			set_escape_mode(&escape, cmdline[i]);
		if (status == SUCCESS && !escape.mode && check_operators(cmdline + i))
			status = ft_vector_add(&vector, " ");
		i++;
	}
	status = ft_vector_add(&vector, "\0");
	if (status == SUCCESS)
		status = ft_vector_trim(&vector, vector.total);
	*ptr = vector.ptr;
	return (status);
}

static int	check_operators(char *ptr)
{
	const char	c1 = *ptr;
	const char	c2 = *(ptr + 1);

	if (ft_ischarset(c1, __PARENTHESIS) && ft_ischarset(c2, __METACHARACTER))
		return (1);
	if (ft_ischarset(c1, __METACHARACTER) && ft_ischarset(c2, __PARENTHESIS))
		return (1);
	if (ft_ischarset(c1, __METACHARACTER) && ft_ischarset(c2, __METACHARACTER))
		return (0);
	if (!ft_ischarset(c1, __DEFAULT_IFS) && ft_ischarset(c2, __METACHARACTER))
		return (1);
	if (ft_ischarset(c1, __METACHARACTER) && !ft_ischarset(c2, __DEFAULT_IFS))
		return (1);
	return (0);
}

static void	set_escape_mode(t_escape *escape, char c)
{
	if (c == '\"' && !escape->double_quote)
	{
		if (escape->single_quote)
			escape->single_quote = false;
		else
			escape->single_quote = true;
	}
	if (c == '\'')
	{
		if (escape->double_quote)
			escape->double_quote = false;
		else
			escape->double_quote = true;
	}
	if (escape->double_quote)
		escape->mode = _DOUBLE;
	else if (escape->single_quote)
		escape->mode = _SINGLE;
	else
		escape->mode = _NONE;
}
