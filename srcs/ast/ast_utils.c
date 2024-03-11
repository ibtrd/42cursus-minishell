/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:57:11 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/11 01:18:41 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

#include "libft.h"

#include "minishelldef.h"
#include "ast.h"

int	ast_newnode(t_astnode **new, t_nodetype type, t_vector *args)
{
	t_astnode	*ptr;

	ptr = malloc(sizeof(t_astnode));
	if (!ptr)
	{
		*new = NULL;
		return (FAILURE);
	}
	ptr->args = args;
	ptr->type = type;
	ptr->left = NULL;
	ptr->right = NULL;
	*new = ptr;
	return (SUCCESS);
}

t_astnode	*free_ast(t_astnode *root)
{
	if (!root)
		return (NULL);
	ft_vector_dealloc(&root->args, 1);
	free_ast(root->left);
	free_ast(root->right);
	free(root);
	return (NULL);
}

void	del_args(void	**ptr)
{
	t_vector	*vector;

	vector = (t_vector *)ptr;
	ft_vector_free(vector);
}
