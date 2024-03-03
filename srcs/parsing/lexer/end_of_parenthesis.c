/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_parenthesis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 04:53:38 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/03 23:53:18 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

#include <stdio.h> //REMOVE

static int	redirection_token(t_vector *vector, size_t index);

int	end_of_parenthesis(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	#ifdef DEBUG
	printf("Inner parentheis closed!\n");
	#endif
	if (ptr->type == _CMD_TOK || ptr->type == _OPEN_PARENTHESIS_TOK)
		return (syntax_error(ptr->value));
	if (ptr->type >= _REDIR_INPUT_TOK && ptr->type <= _REDIR_APPEND_TOK)
		return(redirection_token(vector, index + 1));
	#ifdef DEBUG
	printf("Parenthesis returning index %zu\n", index);
	#endif
	return (index);
}

static int	redirection_token(t_vector *vector, size_t index)
{
	t_lexer_token	*ptr;

	ptr = ft_vector_get(vector, index);
	#ifdef DEBUG
	printf("end of parenthesis mode | index = %zu | tok = %s\n" , index, ptr->value);
	#endif
	if (ptr->type != _CMD_TOK)
		return (syntax_error(ptr->value));
	ptr->type = _FILE_TOK;
	return (end_of_parenthesis(vector, index + 1));
}
