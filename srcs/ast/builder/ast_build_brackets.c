/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build_brackets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:13:10 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/08 00:38:00 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

#include "testing.h" //REMOVE

static t_astnode	*close_bracket(t_vector *lexer, int *index, t_astnode *subroot);
static t_astnode	*link_roots(t_astnode *root, t_astnode *subroot);
static t_astnode	*link_branch(t_astnode *link, t_astnode *subroot);

t_astnode	*ast_build_brackets(t_astnode *root, t_vector *lexer, int *index)
{
	t_astnode		*subroot;
	t_lexer_token	*tok;

	subroot = NULL;
	tok = ft_vector_get(lexer, ++(*index));
	while (tok->type != _CLOSE_BRACKETS_TOK)
	{
		// printf("inner loop:	index %d (type %d)\n", *index, tok->type); //REMOVE
		if (tok->type == _OPEN_BRACKETS_TOK)
		{
			subroot = ast_build_brackets(subroot, lexer, index);
			if (!subroot)
				return (NULL);
		}
		else if (build_from_token(tok, &subroot))
		{
			free_ast(root);
			return (free_ast(subroot));
		}
		tok = ft_vector_get(lexer, ++(*index));
		print2D(2, subroot, "\e[33m"); //REMOVE
	}
	// printf("inner loop:	index %d (type %d)\n", *index, tok->type); //REMOVE
	subroot = close_bracket(lexer, index, subroot); //PROTECTION
	if (!subroot)
		return (free_ast(root));
	return(link_roots(root, subroot));
}


static t_astnode	*close_bracket(t_vector *lexer, int *index, t_astnode *subroot)
{
	t_astnode		*branch;
	t_lexer_token	*tok;

	branch = NULL;
	tok = ft_vector_get(lexer, ++(*index));
	while (tok->type != _END_TOK && tok->type != _CLOSE_BRACKETS_TOK
		&& tok->type > _OR_TOK)
	{
		// printf("closing loop:	index %d (type %d)\n", *index, tok->type); //REMOVE
		if (build_from_token(tok, &branch))
		{
			free_ast(subroot);
			return (free_ast(branch));
		}
		print2D(2, branch, "\e[31m"); //REMOVE
		if (tok->type == _PIPE_TOK)
			return (link_branch(branch, subroot));
		tok = ft_vector_get(lexer, ++(*index));
	}
	// printf("close break index %d (type %d)\n", *index, tok->type); //REMOVE
	(*index)--;
	return (link_branch(branch, subroot));
}

static t_astnode	*link_roots(t_astnode *root, t_astnode *subroot)
{
	if (!root)
		return (subroot);
	if (root->right)
	{
		root->right = link_roots(root->right, subroot);
		return (root);
	}
	root->right = subroot;
	return (root);
}

static t_astnode	*link_branch(t_astnode *link, t_astnode *subroot)
{
	if (!link)
		return (subroot);
	if (link->type <= _PIPE)
	{
		if (link->left)
			link->left = link_branch(link->left, subroot);
		else
			link->left = subroot;
		return (link);
	}
	if (link->type <= _APPEND)
	{
		if (link->right)
			link->right = link_branch(link->right, subroot);
		else
			link->right = subroot;
		return (link);
	}
	printf("link_branch() failed!\n"); //REMOVE
	return (NULL); // REMOVE
}
