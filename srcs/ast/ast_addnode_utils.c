/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_add_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:31:04 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/07 23:34:27 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_astnode	*ast_growleft(t_astnode *root, t_astnode *new)
{
	new->left = root;
	return (new);
}

t_astnode	*ast_growright(t_astnode *root, t_astnode *new)
{
	new->right = root;
	return (new);
}

t_astnode	*ast_addright(t_astnode *root, t_astnode *new)
{
	if (root->right)
		root->right = ast_addnode(root->right, new);
	else
		root->right = new;
	return (root);
}

t_astnode	*ast_addleft(t_astnode *root, t_astnode *new)
{
	if (root->left)
		root->left = ast_addnode(root->left, new);
	else
		root->left = new;
	return (root);
}
