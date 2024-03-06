/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build_launch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:44:13 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/05 22:06:47 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "ast.h"

static int	build_from_token(t_lexer_token *tok, t_astnode **root);

t_astnode	*ast_build_launch(t_vector *lexer)
{
	int				index;
	t_lexer_token	*tok;
	t_astnode		*root;

	root = NULL;
	index = 0;
	tok = ft_vector_get(lexer, index++);
	while (tok->type != _END_TOK)
	{
		if (build_from_token(tok, &root))
			return (free_ast(root));
		tok = ft_vector_get(lexer, index++);
	}
	ft_vector_free(lexer, NULL);
	return (root);
}

static int	build_from_token(t_lexer_token *tok, t_astnode **root)
{
	static t_vector	*arg_v = NULL;
	static t_vector	*file_v = NULL;

	if (tok->type <= _PIPE_TOK)
		return (build_operator(tok, root));
	if (tok->type <= _REDIR_APPEND_TOK)
		return (build_redirection(&file_v, tok, root));
	if (tok->type == _FILE_TOK)
		return (ft_vector_add_ptr(file_v, tok->value));
	if (tok->type == _CMD_TOK)
		return (build_command(&arg_v, tok, root));
	if (tok->type == _ARG_TOK)
		return (ft_vector_insert_ptr(arg_v, tok->value, arg_v->total - 1));
	ft_dprintf(2, "BUILDING BAD TOKEN!\n");
	return (FAILURE);
}
