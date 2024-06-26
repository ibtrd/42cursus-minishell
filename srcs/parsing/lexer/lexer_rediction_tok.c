/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_rediction_tok.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:16:34 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/07 19:26:10 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	lexer_redirection_tok(t_vector *vector, size_t index, t_brackets mode)
{
	t_lexer_token	*ptr;

	ptr = ft_vector_get(vector, index);
	if (ptr->type == _UNSUPPORTED_TOK)
		return (unsupported_error(ptr->value));
	if (ptr->type != _CMD_TOK)
		return (syntax_error(ptr->value));
	ptr->type = _FILE_TOK;
	if (mode == _CLOSED)
		return (lexer_close_bracket(vector, index + 1));
	return (lexer_next_tok(vector, index + 1, mode));
}
