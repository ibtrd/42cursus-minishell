/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:37:35 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 23:57:17 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ast.h"

void	printnode(int fd, t_astnode *node);

void	dprint_ast_util(int fd, t_astnode *root, int space)
{
	int	i;

	if (root == NULL)
		return ;
	space += 3;
	dprint_ast_util(fd, root->right, space);
	i = 3;
	while (i++ < space)
		dprintf(fd, " ");
	printnode(fd, root);
	dprint_ast_util(fd, root->left, space);
}

void	dprint_ast(int fd, t_astnode *root, char *color)
{
	if (color)
		dprintf(2, "\n%s", color);
	else
		dprintf(2, "\n");
	dprint_ast_util(fd, root, 0);
	dprintf(2, "\e[0m\n---------------------------------------------\n");
}

void	printnode(int fd, t_astnode *node)
{
	const char	*operator[] = {"&&", "||", "|", "<", ">", "<<", ">>"};
	t_vector	*str;
	size_t		i;

	i = 0;
	if (node->type >= _AND && node->type <= _APPEND)
		dprintf(fd, "%s ", operator[node->type]);
	if (node->type == _CMD || (node->type >= _INPUT && node->type <= _APPEND))
	{
		str = ft_vector_get(node->args, i);
		while (i++ < node->args->total)
		{
			dprintf(fd, "%s ", (char *)str->ptr);
			str = ft_vector_get(node->args, i);
		}
	}
	dprintf(fd, "\n");
}
