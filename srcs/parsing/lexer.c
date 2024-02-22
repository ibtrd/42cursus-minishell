/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:06:57 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/19 00:53:14 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "minishell_ast.h"
#include "libft.h"

char	**minishell_lexer(char *str)
{
	t_vector	vector;
	char		*tok;

	if (FAILURE == ft_vector_init(&vector, sizeof(char *)))
		return (NULL);
	tok = ft_strtok(str, __DEFAULT_IFS);
	while (tok)
	{
		if (FAILURE == ft_vector_add(&vector, tok))
		{
			ft_vector_free(&vector);
			return (NULL);
		}
		tok = ft_strtok(NULL, __DEFAULT_IFS);
	}
}

int	is_operator(char *tok)
{
	int			i;
	const char	*operator[] = {
		__AND,
		__OR,
		__PIPE,
		__REDIR_INPUT,
		__REDIR_OUTPUT,
		__REDIR_HEREDOC,
		__REDIR_APPEND,
		NULL
	};

	i = 0;
	while (operator[i])
	{
		if (!ft_strcmp(tok, operator[i++]))
			return (1);
	}
	return (0);
}
