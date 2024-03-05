/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_launch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:11:23 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/04 02:19:08 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

#include <stdio.h> //REMOVE

int	lexer_launch(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	#ifdef DEBUG
	printf("\n\nINIT | index = %zu\n", index);
	#endif
	if (ptr->type == _END_TOK)
		return (SUCCESS);
	if (ptr->type == _UNSUPPORTED_TOK)
		return (unsupported_error(ptr->value));
	if (ptr->type <= _PIPE_TOK)
		return (syntax_error(ptr->value));
	if (ptr->type >= _REDIR_INPUT_TOK && ptr->type <= _REDIR_APPEND_TOK)
		return (lexer_redirection_tok(vector, index + 1, _NO_BRACKETS));
	if (ptr->type == _OPEN_BRACKETS_TOK)
	{
		#ifdef DEBUG
		printf("Opening parenthesis from START\n");
		#endif
		index = lexer_open_bracket(vector, index + 1);
		if ((int)index == FAILURE)
			return (FAILURE);
		#ifdef DEBUG
		printf("parenthesis closed, returned OK!\n");
		#endif
		return (lexer_next_tok(vector, index, _NO_BRACKETS));
	}
	return (lexer_next_tok(vector, index + 1, _NO_BRACKETS));
}



