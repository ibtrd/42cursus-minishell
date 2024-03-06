/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_addnode_subroot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:56:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/06 18:14:36 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

#include <stdio.h> //REMOVE

// t_astnode *ast_addnode_subroot(t_astnode *subroot, t_astnode *new)
// {
// 	if (subroot->type <= _OR)
// 	{
// 		new->right = subroot;
// 		return (new);
// 	}
// 	// if (new->type == _PIPE)
// 	// {
// 	// 	if (subroot->right)
// 	// 		subroot->right = ast_addnode(subroot->right, new);
// 	// 	else
// 	// 		subroot->right = new;
// 	// 	return (subroot);
// 	// }
// 	if (subroot->type >= _INPUT && subroot->type <= _APPEND)
// 	{
// 		if (subroot->right)
// 			subroot->right = ast_addnode_subroot(subroot->right, new);
// 		else
// 			subroot->right = new;
// 		return (subroot);
// 	}
// 	printf("\e[31;40;1mADD_ON_SUBROOT FAILED!\e[0m\n"); //REMOVE
// 	return (NULL); //REMOVE
// }

t_astnode	*ast_addnode_subroot(t_astnode *subroot, t_astnode *new)
{
	if (!subroot)
		return (new);
	if (subroot->type <= _OR)
	{
		new->right = subroot;
		return (new);
	}
	if (subroot->type >= _INPUT && subroot->type <= _APPEND)
	{
		if (subroot->right)
			subroot->right = ast_addnode_subroot(subroot->right, new);
		else
			subroot->right = new;
		return (subroot);
	}
	if (subroot->type >= _PIPE)
	{
		if (subroot->right)
			subroot->right = ast_addnode_subroot(subroot->right, new);
		else
			subroot->right = new;
		return (subroot);
	}
	// if (subroot->type == _PIPE)
	// 	return (ast_add_pipe(subroot, new));
	// if (subroot->type >= _INPUT && subroot->type <= _APPEND)
	// 	return (ast_add_redirection(subroot, new));
	printf("\e[31;40;1mADD_ON_SUBROOT FAILED! (type %d)\e[0m\n", new->type); //REMOVE
	return (NULL);
}