/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:37:35 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/08 03:10:18 by ibertran         ###   ########lyon.fr   */
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
	size_t i = 0;

	if (node->type == _AND)
		dprintf(fd, "&&\n");
	if (node->type == _OR)
		dprintf(fd, "||\n");
	if (node->type == _PIPE)
		dprintf(fd, "|\n");
	if (node->type == _INPUT)
	{
		dprintf(fd, "< %s\n", *(char **)node->args->ptr);
	}
	if (node->type == _OUTPUT)
		dprintf(fd, "> %s\n", *(char **)node->args->ptr);
	if (node->type == _HEREDOC)
		dprintf(fd, "<< %s\n", *(char **)node->args->ptr);
	if (node->type == _APPEND)
		dprintf(fd, ">> %s\n", *(char **)node->args->ptr);
	if (node->type == _CMD)
	{

		while (i < node->args->total)
			dprintf(fd, "%s ", ((char **)node->args->ptr)[i++]);
		dprintf(fd, "\n");
	}
}
