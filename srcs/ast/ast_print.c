/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:37:35 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 23:38:29 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ast.h"

#define COUNT 3

void printnode(int fd, t_astnode *node);

void dprint_astUtil(int fd, t_astnode* root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
 
    dprint_astUtil(fd, root->right, space);
 
    for (int i = COUNT; i < space; i++)
        dprintf(fd, " ");
    printnode(fd, root);
 
    dprint_astUtil(fd, root->left, space);
}
 
void dprint_ast(int fd, t_astnode* root, char *color)
{
	if (color)
		dprintf(2, "\n%s", color);
	else
		dprintf(2, "\n");
    dprint_astUtil(fd, root, 0);
	dprintf(2,"\e[0m\n---------------------------------------------\n");
}

void printnode(int fd, t_astnode *node)
{
	size_t 		i = 0;
	t_vector	*str;

	i = 0;
	if (node->type == _AND)
		dprintf(fd, "&&\n");
	if (node->type == _OR)
		dprintf(fd, "||\n");
	if (node->type == _PIPE)
		dprintf(fd, "|\n");
	if (node->type == _INPUT)
	{
		str = ft_vector_get(node->args, i);
		dprintf(fd, "< ");
	}
	if (node->type == _OUTPUT)
	{
		str = ft_vector_get(node->args, i);
		dprintf(fd, "> ");
	}
	if (node->type == _HEREDOC)
	{
		str = ft_vector_get(node->args, i);
		dprintf(fd, "<< ");
	}
	if (node->type == _APPEND)
	{
		str = ft_vector_get(node->args, i);
		dprintf(fd, ">> ");
	}
	if (node->type == _CMD || (node->type >= _INPUT && node->type <= _APPEND))
	{
		str = ft_vector_get(node->args, i);
		while (i++ < node->args->total)
		{
			dprintf(fd, "%s ", (char *)str->ptr);
			str = ft_vector_get(node->args, i);
		}
		dprintf(fd, "\n");
	}
}
