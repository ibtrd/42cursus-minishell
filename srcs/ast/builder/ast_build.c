/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:44:13 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/05 22:06:47 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ast.h"

/*
	DESCRIPTION
	The ast_build() function creates an Abstract Syntax Tree based on the
	tokens contained inside the vector pointed to by lexer. Memory for
	the tree is obtained with malloc(), and can be freed with free_ast().

	RETURN VALUE
	On succes, a pointer to the root of the tree in returned. On error,
	NULL is returned and an error message is printed on standard error.
*/

t_astnode	*ast_build(t_vector *lexer)
{
	int				index;
	t_lexer_token	*tok;
	t_astnode		*root;

	root = NULL;
	index = 0;
	tok = ft_vector_get(lexer, index);
	while (tok->type != _END_TOK)
	{
		if (tok->type == _OPEN_BRACKETS_TOK)
		{
			root = ast_build_brackets(root, lexer, &index);
			if (!root)
				return (NULL);
		}
		else if (build_from_token(tok, &root))
			return (ast_builderror(root));
		tok = ft_vector_get(lexer, ++index);
	}
	return (root);
}

int	build_from_token(t_lexer_token *tok, t_astnode **root)
{
	static t_vector	*arg_v = NULL;
	static t_vector	*file_v = NULL;

	if (tok->type <= _PIPE_TOK)
		return (build_operator(tok, root));
	if (tok->type <= _REDIR_APPEND_TOK)
		return (build_redirection(&file_v, tok, root));
	if (tok->type == _FILE_TOK)
		return (add_argument(file_v, tok->value));
	if (tok->type == _CMD_TOK)
		return (build_command(&arg_v, tok, root));
	if (tok->type == _ARG_TOK)
		return (add_argument(arg_v, tok->value));
	return (FAILURE);
}
