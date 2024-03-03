/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:11:23 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/03 04:49:16 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishelldef.h"
#include "lexer.h"
#include "libft.h"

#include <stdio.h> //REMOVE

static int	next_token(t_vector *vector, size_t index);
static int	logical_operator_token(t_vector *vector, size_t index);
static int	redirection_token(t_vector *vector, size_t index);
static int	end_of_parenthesis(t_vector *vector, size_t index);

int	lexer_analysis(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	printf("\n\nINIT | index = %zu\n", index);
	if (ptr->type == _END_TOK)
		return (SUCCESS);
	if (ptr->type == _UNSUPPORTED_TOK)
		return (unsupported_token(ptr->value));
	if (ptr->type <= _PIPE_TOK)
		return (syntax_error(ptr->value));
	if (ptr->type >= _REDIR_INPUT_TOK && ptr->type <= _REDIR_APPEND_TOK)
		return (redirection_token(vector, index));
	if (ptr->type == _OPEN_PARENTHESIS_TOK)
	{
		printf("Opening parenthesis from START\n");
		index = parenthesis_analysis(vector, index + 1);
		if (index == (size_t)FAILURE)
			return (FAILURE);
		printf("parenthesis closed, returned OK!\n");
		return (end_of_parenthesis(vector, index));
	}
	return (next_token(vector, index + 1));
}

static int	next_token(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	printf("normal mode | index = %zu | tok = %s\n" , index, ptr->value);
	if (ptr->type == _END_TOK)
		return (SUCCESS);
	if (ptr->type == _UNSUPPORTED_TOK)
		return (unsupported_token(ptr->value));
	if (ptr->type == _OPEN_PARENTHESIS_TOK || ptr->type == _CLOSE_PARENTHESIS_TOK)
		return (syntax_error(ptr->value));
	if (ptr->type >= _REDIR_INPUT_TOK && ptr->type <= _REDIR_APPEND_TOK)
		return (redirection_token(vector, index + 1));
	if (ptr->type <= _PIPE_TOK)
		return (logical_operator_token(vector, index + 1));
	return (next_token(vector, index + 1));
}

static int	logical_operator_token(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	printf("normal mode | index = %zu | tok = %s\n" , index, ptr->value);
	if (ptr->type == _UNSUPPORTED_TOK)
		return (unsupported_token(ptr->value));
	if (ptr->type == _END_TOK || ptr->type == _CLOSE_PARENTHESIS_TOK)
		return (syntax_error(ptr->value));
	if (ptr->type <= _PIPE_TOK)
		return (syntax_error(ptr->value));
	if (ptr->type >= _REDIR_INPUT_TOK && ptr->type <= _REDIR_APPEND_TOK)
		return (redirection_token(vector, index + 1));
	if (ptr->type == _OPEN_PARENTHESIS_TOK)
	{
		printf("Opening parenthesis from LOGICAL\n");
		index = parenthesis_analysis(vector, index + 1);
		if (index == (size_t)FAILURE)
			return (FAILURE);
		return (end_of_parenthesis(vector, index));
	}
	return (next_token(vector, index + 1));
}

static int	redirection_token(t_vector *vector, size_t index)
{
	t_lexer_token	*ptr;

	ptr = ft_vector_get(vector, index);
	printf("normal mode | index = %zu | tok = %s\n" , index, ptr->value);
	if (ptr->type != _CMD_TOK)
		return (syntax_error(ptr->value));
	ptr->type = _FILE_TOK;
	return (next_token(vector, index + 1));
}

static int	end_of_parenthesis(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	printf("returned OK! to MAIN\n");
	if (ptr->type == _END_TOK)
		return (SUCCESS);
	if (ptr->type == _CMD_TOK || ptr->type == _OPEN_PARENTHESIS_TOK)
		return (syntax_error(ptr->value));
	return (next_token(vector, index));
}
