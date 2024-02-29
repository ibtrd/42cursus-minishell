/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline_addspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:24:34 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/29 19:32:30 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "parsing.h"
#include "minishelldef.h"
#include "libft.h"

static int	check_operators(char *ptr);

/*
	DESCRIPTION
	The cmdline_addspace() function add a space character before and after
	each operator or parenthesis if they are are not already prefixed
	or suffixed by a whitespace character. The resulting string is
	attached to the string pointed by ptr. Memory for the new string
	is obtained with malloc(), and can be freed with free().
	
	RETURN VALUE
	The cmdline_addspace() function return 0.
	On error, cmdline_addspace() return -1 and the string pointed by ptr
	is set to NULL.
*/

int	cmdline_addspace(char *cmdline, char **ptr)
{
	int			status;
	t_vector	vector;
	t_escape	escape;
	int			i;

	status = ft_vector_init(&vector, sizeof(char), 0);
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
		status = ft_vector_trim(&vector);
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

