/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_operator_tok.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 02:19:01 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/06 11:44:46 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	lexer_operator_tok(t_vector *vector, size_t index, t_brackets mode)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	if (ptr->type == _UNSUPPORTED_TOK)
		return (unsupported_error(ptr->value));
	if (ptr->type == _END_TOK || ptr->type == _CLOSE_BRACKETS_TOK)
		return (syntax_error(ptr->value));
	if (ptr->type <= _PIPE_TOK)
		return (syntax_error(ptr->value));
	if (ptr->type >= _REDIR_INPUT_TOK && ptr->type <= _REDIR_APPEND_TOK)
		return (lexer_redirection_tok(vector, index + 1, mode));
	if (ptr->type == _OPEN_BRACKETS_TOK)
	{
		index = lexer_open_bracket(vector, index + 1);
		if ((int)index == FAILURE)
			return (FAILURE);
		return (lexer_next_tok(vector, index, mode));
	}
	return (lexer_next_tok(vector, index + 1, mode));
}
