/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_analysis_parenthesis.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:29:57 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/02 22:00:24 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishelldef.h"
#include "lexer.h"
#include "libft.h"

#include <stdio.h> //REMOVE

static int	logical_operator_token(t_vector *vector, size_t index);
static int	redirection_token(t_vector *vector, size_t index);

int	parenthesis_analysis(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	printf("parenthesis mode | index = %zu\n", index);
	if (ptr->type == _CLOSE_PARENTHESIS_TOK)
		return (index);
	if (ptr->type == _UNSUPPORTED_TOK || ptr->type == _END_TOK)
		return (syntax_error(ptr->value));
	if (ptr->type >= _REDIR_INPUT_TOK && ptr->type <= _REDIR_APPEND_TOK)
		return (redirection_token(vector, index + 1));
	if (ptr->type == _AND_TOK || ptr->type == _OR_TOK || ptr->type == _PIPE_TOK)
		return (logical_operator_token(vector, index + 1));
	if (ptr->type == _OPEN_PARENTHESIS_TOK)
	{
		printf("Opening parenthesis\n");
		index = parenthesis_analysis(vector, index + 1);
		if (index == (size_t)FAILURE)
			return (FAILURE);
		printf("parenthesis closed, returned OK!\n");
	}
	return (parenthesis_analysis(vector, index + 1));
}

static int	logical_operator_token(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

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
		printf("Opening parenthesis from logical\n");
		index = parenthesis_analysis(vector, index + 1);
		if (index == (size_t)FAILURE)
			return (FAILURE);
		printf("parenthesis closed, returned OK!\n");
	}
	return (parenthesis_analysis(vector, index + 1));
}

static int	redirection_token(t_vector *vector, size_t index)
{
	t_lexer_token	*ptr;

	ptr = ft_vector_get(vector, index);
	if (!ptr || ptr->type != _CMD_TOK)
		return (syntax_error(ptr->value));
	ptr->type = _FILE_TOK;
	return (parenthesis_analysis(vector, index + 1));
}