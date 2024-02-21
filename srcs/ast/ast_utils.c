/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:57:11 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/21 14:32:02 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

#include "minishell_def.h"
#include "minishell_ast.h"
#include "libft.h"

int	ast_newnode(t_astnode **new, t_nodetype type, t_vector *args)
{
	t_astnode	*ptr;
	int			status;

	status = UNDEFINED;
	ptr = malloc(sizeof(t_astnode));
	if (ptr)
	{
		ptr->args = args;
		ptr->type = type;
		ptr->left = NULL;
		ptr->right = NULL;
	}
	*new = ptr;
	return (status);
}

void	free_ast(t_astnode *root)
{
	if (!root)
		return ;
	if (root->type == _CMD)
	{
		ft_vector_free(root->args);
		free(root->args);
	}
	free_ast(root->left);
	free_ast(root->right);
	free(root);
}

