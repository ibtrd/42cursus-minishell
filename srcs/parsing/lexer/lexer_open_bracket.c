/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_open_bracket.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:29:57 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/04 02:00:20 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

#include <stdio.h> //REMOVE

int	lexer_open_bracket(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	#ifdef DEBUG
	printf("parenthesis mode INIT | index = %zu\n", index);
	#endif
	if (ptr->type == _UNSUPPORTED_TOK)
		return (unsupported_error(ptr->value));
	if (ptr->type == _END_TOK)
		return (FAILURE);
	if (ptr->type <= _PIPE_TOK || ptr->type == _CLOSE_BRACKETS_TOK)
		return (syntax_error(ptr->value));
	if (ptr->type == _OPEN_BRACKETS_TOK)
	{
		#ifdef DEBUG
		printf("Opening parenthesis from PARENTHESIS\n");
		#endif
		index = lexer_open_bracket(vector, index + 1);
		if ((int)index == FAILURE)
			return (FAILURE);
		return (lexer_next_tok(vector, index, _OPENED));
	}
	return (lexer_next_tok(vector, index + 1, _OPENED));
}

