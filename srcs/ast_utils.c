/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:57:11 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/19 00:52:18 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

#include "minishell_def.h"
#include "minishell_ast.h"
#include "libft.h"

int	ast_newnode(t_astnode **new, t_nodetype type, char **args)
{
	t_astnode	*ptr;

	ptr = malloc(sizeof(t_astnode));
	if (!ptr)
		return (FAILURE);
	ptr->type = type;
	ptr->argv = args;
	ptr->left = NULL;
	ptr->right = NULL;
	*new = ptr;
	return (SUCCESS);
}

void	free_ast(t_astnode *root)
{
	if (!root)
		return ;
	ft_free_2darray_char(root->argv);
	free_ast(root->left);
	free_ast(root->right);
	free(root);
}

