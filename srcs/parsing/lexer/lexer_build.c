/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:06:57 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/02 00:02:54 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "parsing.h"
#include "lexer.h"
#include "libft.h"

static int	compare_operators(char *tok);
static int	is_invalid_operator(char *tok);

int	lexer_build(char *cmdline, t_vector *vector)
{
	int				status;
	t_lexer_token	tok;

	status = ft_vector_init(vector, sizeof(t_lexer_token), 0);
	tok.value = cmdline_tokenizer(cmdline);
	while (status == SUCCESS && tok.value)
	{
		tok.type = compare_operators(tok.value);
		status = ft_vector_add(vector, &tok);
		tok.value = cmdline_tokenizer(NULL);
	}
	if (status == SUCCESS)
		ft_vector_add(vector, &(t_lexer_token){_END_TOK, "\\n"});
	if (status == SUCCESS)
		ft_vector_trim(vector);
	else
		ft_vector_free(vector, NULL);
	return (status);
}

static int	compare_operators(char *tok)
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
		__OPEN_PARENTHESIS,
		__CLOSE_PARENTHESIS,
		NULL
	};

	i = 0;
	while (operator[i])
	{
		if (!ft_strcmp(tok, operator[i]))
			return (i);
		i++;
	}
	if (is_invalid_operator(tok))
		return (_INVALID_TOK);
	return (_CMD_TOK);
}

static int	is_invalid_operator(char *tok)
{
	t_escape	escape;
	char		c;

	init_escape(&escape);
	c = *tok++;
	while (!escape.mode && c)
	{
		set_escape_mode(&escape, c);
		if (ft_ischarset(c, __METACHARACTER))
			return (FAILURE);
		c = *tok++;
	}
	return (SUCCESS);
}
