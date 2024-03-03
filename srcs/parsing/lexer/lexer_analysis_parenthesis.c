/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_analysis_parenthesis.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:29:57 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/03 23:53:28 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

#include <stdio.h> //REMOVE

static int	next_token_parenthesis(t_vector *vector, size_t index);
static int	logical_operator_token(t_vector *vector, size_t index);
static int	redirection_token(t_vector *vector, size_t index);

int	parenthesis_analysis(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	#ifdef DEBUG
	printf("parenthesis mode INIT | index = %zu\n", index);
	#endif
	if (ptr->type == _END_TOK)
		return (FAILURE);
	if (ptr->type == _UNSUPPORTED_TOK)
		return (unsupported_token(ptr->value));
	if (ptr->type <= _PIPE_TOK || ptr->type == _CLOSE_PARENTHESIS_TOK)
		return (syntax_error(ptr->value));
	if (ptr->type == _OPEN_PARENTHESIS_TOK)
	{
		#ifdef DEBUG
		printf("Opening parenthesis from PARENTHESIS\n");
		#endif
		index = parenthesis_analysis(vector, index + 1);
		if ((int)index == FAILURE)
			return (FAILURE);
		return (next_token_parenthesis(vector, index));
	}
	return (next_token_parenthesis(vector, index + 1));
}

static int	next_token_parenthesis(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	#ifdef DEBUG
	printf("parenthesis mode | index = %zu | tok = %s\n" , index, ptr->value);
	#endif
	if (ptr->type == _CLOSE_PARENTHESIS_TOK)
		return (end_of_parenthesis(vector, index + 1));
	if (ptr->type == _UNSUPPORTED_TOK || ptr->type == _END_TOK || ptr->type == _OPEN_PARENTHESIS_TOK)
		return (syntax_error(ptr->value));
	if (ptr->type >= _REDIR_INPUT_TOK && ptr->type <= _REDIR_APPEND_TOK)
		return (redirection_token(vector, index + 1));
	if (ptr->type == _AND_TOK || ptr->type == _OR_TOK || ptr->type == _PIPE_TOK)
		return (logical_operator_token(vector, index + 1));
	return (next_token_parenthesis(vector, index + 1));
}

static int	logical_operator_token(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	#ifdef DEBUG
	printf("parenthesis mode | index = %zu | tok = %s\n" , index, ptr->value);
	#endif
	if ((ptr - 2)->type == _OPEN_PARENTHESIS_TOK)
		return (syntax_error((ptr - 1)->value));
	if (ptr->type == _UNSUPPORTED_TOK || ptr->type == _CLOSE_PARENTHESIS_TOK || ptr->type == _END_TOK)
		return (syntax_error(ptr->value));
	if (ptr->type >= _AND_TOK && ptr->type <= _PIPE_TOK)
		return (syntax_error(ptr->value));
	if (ptr->type >= _REDIR_INPUT_TOK && ptr->type <= _REDIR_APPEND_TOK)
		return (redirection_token(vector, index + 1));
	if (ptr->type == _OPEN_PARENTHESIS_TOK)
	{
		#ifdef DEBUG
		printf("Opening parenthesis from LOGICAL PARENTHESIS\n");
		#endif
		index = parenthesis_analysis(vector, index + 1);
		if ((int)index == FAILURE)
			return (FAILURE);
		#ifdef DEBUG
		printf("Parenthesis returning index %zu\n", index);
		#endif
		return (next_token_parenthesis(vector, index));
	}
	return (next_token_parenthesis(vector, index + 1));
}

static int	redirection_token(t_vector *vector, size_t index)
{
	t_lexer_token	*ptr;

	ptr = ft_vector_get(vector, index);
	#ifdef DEBUG
	printf("parenthesis mode | index = %zu | tok = %s\n" , index, ptr->value);
	#endif
	if (ptr->type != _CMD_TOK)
		return (syntax_error(ptr->value));
	ptr->type = _FILE_TOK;
	return (next_token_parenthesis(vector, index + 1));
}
