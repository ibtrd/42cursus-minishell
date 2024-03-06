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
t_astnode	*build_brackets(t_vector *lexer, int *index, t_break mode);
t_astnode	*close_bracket(t_vector *lexer, int *index, t_astnode **subroot, t_break mode);

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
			if (!root)
			{
				root = build_brackets(lexer, &index, _PIPE_BREAK);
				if (!root)
					return (free_ast(root));
			}
			else
			{
				root->right = build_brackets(lexer, &index, (tok - 1)->type == _PIPE_TOK);
				if (!root->right)
					return (free_ast(root));
			}
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
	ft_dprintf(2, "BUILDING BAD TOKEN! (Type %d)\n", tok->type); //REMOVE
	return (FAILURE);
}

t_astnode	*build_brackets(t_vector *lexer, int *index, t_break mode)
{
	t_lexer_token	*tok;
	t_astnode		*subroot;

	printf("MODE=%d\n", mode);
	subroot = NULL;
	tok = ft_vector_get(lexer, (*index)++);
	while (tok->type != _CLOSE_BRACKETS_TOK)
	{
		if (tok->type == _OPEN_BRACKETS_TOK)
		{
			if (!subroot)
			{
				subroot = build_brackets(lexer, index, _PIPE_BREAK);
				if (!subroot)
					return (free_ast(subroot));
			}
			else
			{
				subroot->right = build_brackets(lexer, index, (tok - 1)->type);
				if (!subroot->right)
					return (free_ast(subroot));
			}
		}
		else if (build_from_token(tok, &subroot))
			return (free_ast(subroot));
		tok = ft_vector_get(lexer, (*index)++);
	}
	subroot = close_bracket(lexer, index, &subroot, mode);
	return (subroot);
}

t_astnode	*close_bracket(t_vector *lexer, int *index, t_astnode **subroot, t_break mode)
{
	t_lexer_token	*tok;

	tok = ft_vector_get(lexer, (*index));
	while (tok->type != _END_TOK
		&& !(mode == _LOGIC_BREAK && tok->type <= _OR_TOK)
		&& !(mode == _PIPE_BREAK && tok->type <= _PIPE_TOK))
	{
		// if (tok->type == _OPEN_BRACKETS_TOK)
		// {
		// 	subroot->right = build_brackets(lexer, index);
		// 	if (!subroot->right)
		// 		return (free_ast(subroot));
		// }
		if (build_token_subroot(tok, subroot))
			return (free_ast(*subroot));
		tok = ft_vector_get(lexer, ++(*index));
	}
	return (*subroot);
}

// t_astnode	*ast_addtree(t_astnode *root, t_vector *lexer, int *index)
// {
// 	t_lexer_token	*tok;
// 	t_astnode		*subroot;

// 	subroot = NULL;
// 	if (!subroot)
// 	{
// 		subroot = build_brackets(lexer, index, _PIPE_BREAK);
// 		if (!subroot)
// 			return (free_ast(root));
// 	}
// 	else
// 	{
// 		subroot->right = build_brackets(lexer, index, (tok - 1)->type);
// 		if (!subroot)
// 			return (free_ast(root));
// 	}
// 	if (!root)
// 		return (subroot);
// 	root->right = subroot;
// 	return (root);
// }
