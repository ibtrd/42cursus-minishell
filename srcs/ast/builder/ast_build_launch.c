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

#include "ast.h"

#include "libft.h" //REMOVE

static int	build_from_token(t_lexer_token *tok, t_astnode **root);
t_astnode	*build_brackets(t_vector *lexer, int *index);

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
		if (tok->type == _OPEN_BRACKETS_TOK)
		{
			root->right = build_brackets(lexer, &index);
			if (!root->right)
				return (free_ast(root));
		}
		else if (build_from_token(tok, &root))
			return (free_ast(root));
		tok = ft_vector_get(lexer, index++);
	}
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
		return (add_file(file_v, tok->value));
	if (tok->type == _CMD_TOK)
		return (build_command(&arg_v, tok, root));
	if (tok->type == _ARG_TOK)
		return (add_argument(arg_v, tok->value));
	ft_dprintf(2, "BUILDING BAD TOKEN!\n"); //REMOVE
	return (FAILURE);
}

t_astnode	*build_brackets(t_vector *lexer, int *index)
{
	t_lexer_token	*tok;
	t_astnode		*subroot = NULL;

	tok = ft_vector_get(lexer, (*index)++);
	while (tok->type != _CLOSE_BRACKETS_TOK)
	{
		if (tok->type == _OPEN_BRACKETS_TOK)
		{
			subroot->right = build_brackets(lexer, index);
			if (!subroot->right)
				return (free_ast(subroot));
		}
		else if (build_from_token(tok, &subroot))
			return (free_ast(subroot));
		tok = ft_vector_get(lexer, (*index)++);
	}
	return (subroot);
}

// t_astnode	*build_brackets_close(t_vector *lexer, int *index, t_astnode **root)
// {
// 	t_lexer_token	*tok;
// 	t_astnode		*subroot;

// 	tok = ft_vector_get(lexer, index++);
// 	while (tok->type > _PIPE_TOK)
// 	{
// 		if (build_from_token(tok, &subroot))
// 			return (free_subroot(subroot));
// 		tok = ft_vector_get(lexer, index++);
// 	}
// 	return (*root);
// }
