/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_addtree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:13:10 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/07 14:36:59 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

#include "testing.h" //REMOVE

t_astnode			*close_bracket(t_vector *lexer, int *index, t_astnode *subroot, t_break mode);
static 	t_astnode	*link_roots(t_astnode *root, t_astnode *subroot);
static t_astnode	*link_roots2(t_astnode *link, t_astnode *subroot);

static t_break		get_break_mode(t_vector *lexer, int index);

t_astnode	*ast_addtree(t_astnode *root, t_vector *lexer, int *index)
{
	const t_break	mode = get_break_mode(lexer, (*index)++);
	t_astnode		*subroot;
	t_lexer_token	*tok;

	subroot = NULL;
	printf("MODE=%d\n", mode);
	tok = ft_vector_get(lexer, *index);
	while (tok->type != _CLOSE_BRACKETS_TOK)
	{
		printf("inner loop:	index %d (type %d)\n", *index, tok->type);
		if (tok->type == _OPEN_BRACKETS_TOK)
		{
			subroot = ast_addtree(subroot, lexer, index);
			if (!subroot)
				return (NULL);
		}
		else if (build_from_token(tok, &subroot))
			return (free_ast(subroot));
		tok = ft_vector_get(lexer, ++(*index));
		print2D(2, subroot, "\e[33m"); //REMOVE
	}
	printf("inner loop:	index %d (type %d)\n", *index, tok->type);
	subroot = close_bracket(lexer, index, subroot, mode);
	return(link_roots(root, subroot));
}


t_astnode	*close_bracket(t_vector *lexer, int *index, t_astnode *subroot, t_break mode)
{
	t_lexer_token		*tok;
	t_astnode			*link = NULL;

	tok = ft_vector_get(lexer, ++(*index));
	while (tok->type != _END_TOK && tok->type != _CLOSE_BRACKETS_TOK
		&& tok->type > _OR_TOK)
		// && !(mode == _PIPE_BREAK && tok->type <= _PIPE_TOK))
	{
		printf("closing loop:	index %d (type %d)\n", *index, tok->type);
		if (build_from_token(tok, &link))
			return (free_ast(link));
		print2D(2, link, "\e[31m"); //REMOVE
		if (tok->type == _PIPE_TOK)
			return (link_roots2(link, subroot));
		tok = ft_vector_get(lexer, ++(*index));
	}
	printf("close break index %d (type %d)\n", *index, tok->type);
	(*index)--;
	return (link_roots2(link, subroot));
	(void)mode;
}						

static t_break	get_break_mode(t_vector *lexer, int index)
{
	t_lexer_token	*tok;

	return (_PIPE_BREAK);
	if (index < 1)
		return (_LOGIC_BREAK);
	tok = ft_vector_get(lexer, index - 1);
	if (!tok || tok->type == _PIPE_TOK)
		return (_PIPE_BREAK);
	return (_LOGIC_BREAK);
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

static t_astnode	*link_roots2(t_astnode *link, t_astnode *subroot)
{
	if (!link)
		return (subroot);
	if (link->type <= _PIPE)
	{
		if (link->left)
			link->left = link_roots2(link->left, subroot);
		else
			link->left = subroot;
		return (link);
	}
	if (link->type <= _APPEND)
	{
		if (link->right)
			link->right = link_roots2(link->right, subroot);
		else
			link->right = subroot;
		return (link);
	}
	printf("link_roots2() failed!\n"); //REMOVE
	return (NULL); // REMOVE
}
