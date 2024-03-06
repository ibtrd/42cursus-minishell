/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_addnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:40:02 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/06 02:04:07 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

#include <stdio.h> //REMOVE

t_astnode	*ast_add_command(t_astnode *root, t_astnode *new)
{
	// printf("\t\t\tadding command!\n");
	if ((new->type >= _INPUT && new->type <= _APPEND))
	{
		new->right = root;
		return (new);
	}
	else
	{
		new->left = root;
		return (new);
	}
	printf("ADD_ON_COMMAND FAILED!\n");
	return(NULL); //REMOVE
}

t_astnode	*ast_add_redirection(t_astnode *root, t_astnode *new)
{
	// printf("\t\t\tadding redirection!\n");
	if (new->type <= _PIPE)
	{
		new->left = root;
		return (new);
	}
	if ((new->type >= _INPUT && new->type <= _APPEND) || new->type == _CMD)
	{
		if (root->right)
			root->right = ast_addnode(root->right, new);
		else
			root->right = new;
		return (root);
	}
	if (new->type == _CMD)
	{
		new->right = root;
		return (new);
	}
	printf("ADD_ON_REDIR FAILED!\n");
	return (NULL);
}

t_astnode	*ast_add_pipe(t_astnode *root, t_astnode *new)
{
	// printf("\t\t\tadding pipe!\n");
	if (new->type <= _OR)
	{
		new->left = root;
		return (new);
	}
	if (new->type <= _PIPE)
	{
		if (root->right)
			root->right = ast_addnode(root->right, new);
		else
			root->right = new;
		return (root);
	}
	if (new->type <= _APPEND)
	{
		if (root->right)
			root->right = ast_addnode(root->right, new);
		else
			root->right = new;
		return (root);
	}
	if (new->type == _CMD)
	{
		if (root->right)
			root->right = ast_addnode(root->right, new);
		else
			root->right = new;
		return (root);
	}
	printf("ADD_ON_PIPE FAILED!\n");
	return (NULL);
}

t_astnode	*ast_add_logicaloperator(t_astnode *root, t_astnode *new)
{
	// printf("\t\t\tadding || - &&!\n");
	if (new->type == _AND || new->type == _OR)
	{
		new->left = root;
		return (new);
	}
	if (root->right)
		root->right = ast_addnode(root->right, new);
	else
		root->right = new;
	return (root);
}

t_astnode	*ast_addnode(t_astnode *root, t_astnode *new)
{
	if (!root)
		return (new);
	if (root->type == _AND || root->type == _OR)
		return (ast_add_logicaloperator(root, new));
	if (root->type == _PIPE)
		return (ast_add_pipe(root, new));
	if (root->type >= _INPUT && root->type <= _APPEND)
		return (ast_add_redirection(root, new));
	return (ast_add_command(root, new));
}
