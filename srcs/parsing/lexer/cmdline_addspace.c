/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline_addspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:24:34 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/08 05:50:04 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "parsing.h"
#include "minishelldef.h"
#include "libft.h"

static int	add_metacharacters(char *cmdline, t_vector *vector, int *index);
static int	compare_operators(char *cmdline, char **ptr);

/*
	DESCRIPTION
	The cmdline_addspace() function add a space character before and after
	each operator or parenthesis. The resulting string is attached to
	the string pointed by ptr. Memory for the new string is obtained with
	malloc(), and can be freed with free().
	
	RETURN VALUE
	The cmdline_addspace() function returns 0.
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
		set_escape_mode(&escape, cmdline[i]);
		if (!escape.mode && ft_ischarset(cmdline[i], __METACHARACTER))
			status = add_metacharacters(cmdline, &vector, &i);
		else
			status = ft_vector_add(&vector, cmdline + i++);
	}
	status = ft_vector_add(&vector, "\0");
	if (status == SUCCESS)
	{
		status = ft_vector_trim(&vector);
		*ptr = vector.ptr;
	}
	else
		*ptr = NULL;
	return (status);
}

static int	add_metacharacters(char *cmdline, t_vector *vector, int *index)
{
	int		status;
	char	*operator;
	int		len;

	len = compare_operators(cmdline + *index, &operator);
	status = SUCCESS;
	if (len)
	{
		status = ft_vector_add(vector, " ");
		if (!status)
			status = ft_vector_join(vector, operator, len);
		if (!status)
			status = ft_vector_add(vector, " ");
		*index += len;
	}
	return (status);
}

static int	compare_operators(char *cmdline, char **ptr)
{
	const char	*operator[] = {
		__UNSUPPORTED_OPERATOR1, __UNSUPPORTED_OPERATOR2,
		__AND, __OR, __REDIR_HEREDOC, __REDIR_APPEND,
		__PIPE, __REDIR_INPUT, __REDIR_OUTPUT,
		__OPEN_RBRACKET, __CLOSE_RBRACKET,
		__UNSUPPORTED_OPERATOR3, __UNSUPPORTED_OPERATOR4, NULL
	};
	size_t		len;
	int			i;

	i = 0;
	while (operator[i])
	{
		len = ft_strlen(operator[i]);
		if (!ft_strncmp(cmdline, operator[i], len))
		{
			*ptr = (char *)operator[i];
			return (len);
		}
		i++;
	}
	return (0);
}
