/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:11:23 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/02 02:45:48 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishelldef.h"
#include "lexer.h"
#include "libft.h"

#include <stdio.h> //REMOVE

static int	logical_operator_token(t_vector *vector, size_t index);
static int	redirection_token(t_vector *vector, size_t index);
static int	syntax_error(const t_lexer_token *token);

int	lexer_analysis(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	// printf("normal mode | index = %zu\n", index);
	if (ptr->type == _END_TOK)
		return (SUCCESS);
	if (ptr->type == _INVALID_TOK || ptr->type == _CLOSE_PARENTHESIS_TOK)
		return (syntax_error(ptr));
	if (ptr->type >= _REDIR_INPUT_TOK && ptr->type <= _REDIR_APPEND_TOK)
		return (redirection_token(vector, index + 1));
	if (ptr->type == _AND_TOK || ptr->type == _OR_TOK || ptr->type == _PIPE_TOK)
		return (logical_operator_token(vector, index + 1));
	if (ptr->type == _OPEN_PARENTHESIS_TOK)
	{
		// printf("Opening parenthesis\n");
		index = parenthesis_analysis(vector, index + 1);
		if (index == (size_t)FAILURE)
			return (FAILURE);
		// printf("parenthesis closed, returned OK!\n");
	}
	return (lexer_analysis(vector, index + 1));
}

static int	logical_operator_token(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	if (index == 1)
		return (syntax_error(ptr - 1));
	if (ptr->type == _INVALID_TOK || ptr->type == _CLOSE_PARENTHESIS_TOK)
		return (syntax_error(ptr));
	if (ptr->type >= _AND_TOK && ptr->type <= _PIPE_TOK)
		return (syntax_error(ptr));
	if (ptr->type == _OPEN_PARENTHESIS_TOK)
	{
		// printf("Opening parenthesis from logical\n");
		index = parenthesis_analysis(vector, index + 1);
		if (index == (size_t)FAILURE)
			return (FAILURE);
		// printf("returned OK!\n");
	}
	return (lexer_analysis(vector, index + 1));
}

static int	redirection_token(t_vector *vector, size_t index)
{
	t_lexer_token	*ptr;

	ptr = ft_vector_get(vector, index);
	if (!ptr || ptr->type != _CMD_TOK)
		return (syntax_error(ptr));
	ptr->type = _FILE_TOK;
	return (lexer_analysis(vector, index + 1));
}

static int	syntax_error(const t_lexer_token *token)
{
	write(STDERR_FILENO, __PRGM_NAME, __PRGM_NAME_LEN);
	write(STDERR_FILENO, __SYNTAX_ERROR, ft_strlen(__SYNTAX_ERROR));
	write(STDERR_FILENO, token->value, ft_strlen(token->value));
	write(STDERR_FILENO, "'\n", 2);
	return (FAILURE);
}
