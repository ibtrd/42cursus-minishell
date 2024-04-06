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

static t_astnode	*close_bracket(t_vector *lexer, int *index, \
															t_astnode *subroot);
static t_astnode	*link_roots(t_astnode *root, t_astnode *subroot);
static t_astnode	*link_branch(t_astnode *link, t_astnode *subroot);

/*
	DESCRIPTION
	The ast_build_brackets() function creates an Abstract Syntax Tree based
	on the tokens contained inside the vector pointed to by lexer for the
	ongoing round bracket. It is then linked to the previously built tree
	pointer by root. Memory for the tree is obtained with malloc(), and can
	be freed with free_ast(). 

	RETURN VALUE
	On succes, a pointer to the root of the resulting tree is returned.
	On error, NULL is returned and a appropriate message is printed on
	standard error.
*/

t_astnode	*ast_build_brackets(t_astnode *root, t_vector *lexer, int *index)
{
	t_astnode		*subroot;
	t_lexer_token	*tok;

	subroot = NULL;
	tok = ft_vector_get(lexer, ++(*index));
	while (tok->type != _CLOSE_BRACKETS_TOK)
	{
		if (tok->type == _OPEN_BRACKETS_TOK)
		{
			subroot = ast_build_brackets(subroot, lexer, index);
			if (!subroot)
				return (NULL); //CHECK PROTECTION
		}
		else if (build_from_token(tok, &subroot))
		{
			free_ast(root);
			return (ast_builderror(subroot));
		}
		tok = ft_vector_get(lexer, ++(*index));
	}
	subroot = close_bracket(lexer, index, subroot); //PROTECTION
	if (!subroot)
		return (ast_builderror(root));
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
		if (build_from_token(tok, &branch))
		{
			free_ast(subroot);
			return (ast_builderror(branch));
		}
		if (tok->type == _PIPE_TOK)
			return (link_branch(branch, subroot));
		tok = ft_vector_get(lexer, ++(*index));
	}
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
	if (link->right)
		link->right = link_branch(link->right, subroot);
	else
		link->right = subroot;
	return (link);
}
