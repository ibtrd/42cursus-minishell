/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_addnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:40:02 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/07 19:38:47 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static t_astnode	*addto_command(t_astnode *root, t_astnode *new);
static t_astnode	*addto_redirection(t_astnode *root, t_astnode *new);
static t_astnode	*addto_pipe(t_astnode *root, t_astnode *new);
static t_astnode	*addto_logicaloperator(t_astnode *root, t_astnode *new);

/*
	DESCRIPTION
	The ast_addnode() function adds the node pointed to by new to the
	Abstract Syntax Tree pointed to by root, based on it's node type.

	RETURN VALUE
	The ast_builderror() function returns a pointer to the root of
	the resulting AST;
*/

t_astnode	*ast_addnode(t_astnode *root, t_astnode *new)
{
	if (!root)
		return (new);
	if (root->type <= _OR)
		return (addto_logicaloperator(root, new));
	if (root->type <= _PIPE)
		return (addto_pipe(root, new));
	if (root->type <= _APPEND)
		return (addto_redirection(root, new));
	return (addto_command(root, new));
}

static t_astnode	*addto_command(t_astnode *root, t_astnode *new)
{
	if ((new->type >= _INPUT && new->type <= _APPEND))
		return (ast_growright(root, new));
	return (ast_growleft(root, new));
}

static t_astnode	*addto_redirection(t_astnode *root, t_astnode *new)
{
	if (new->type <= _PIPE)
		return (ast_growleft(root, new));
	return (ast_addright(root, new));
}

static t_astnode	*addto_pipe(t_astnode *root, t_astnode *new)
{
	if (new->type <= _PIPE)
		return (ast_growleft(root, new));
	return (ast_addright(root, new));
}

static t_astnode	*addto_logicaloperator(t_astnode *root, t_astnode *new)
{
	if (new->type == _AND || new->type == _OR)
		return (ast_growleft(root, new));
	return (ast_addright(root, new));
}
