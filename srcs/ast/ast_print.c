/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:37:35 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/08 20:53:52 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ast.h"

static void	printnode(int fd, t_astnode *node);
static void	print_nextnode(int fd, t_astnode *root, int space);

void	dprint_ast(int fd, t_astnode *root, char *color)
{
	if (color)
		dprintf(2, "\n%s", color);
	else
		dprintf(2, "\n");
	print_nextnode(fd, root, 0);
	dprintf(2,"\e[0m\n---------------------------------------------\n");
}

static void	print_nextnode(int fd, t_astnode *root, int space)
{
	int	i;

	if (root == NULL)
		return ;
	i = 3;
	space += 3;
	print_nextnode(fd, root->right, space);
	while (i++ < space)
		dprintf(fd, " ");
	printnode(fd, root);
	print_nextnode(fd, root->left, space);
}

static void	printnode(int fd, t_astnode *node)
{
	size_t	i;

	if (node->type == _AND)
		dprintf(fd, "&&\n");
	if (node->type == _OR)
		dprintf(fd, "||\n");
	if (node->type == _PIPE)
		dprintf(fd, "|\n");
	if (node->type == _INPUT)
		dprintf(fd, "< %s\n", *(char **)node->args->ptr);
	if (node->type == _OUTPUT)
		dprintf(fd, "> %s\n", *(char **)node->args->ptr);
	if (node->type == _HEREDOC)
		dprintf(fd, "<< %s\n", *(char **)node->args->ptr);
	if (node->type == _APPEND)
		dprintf(fd, ">> %s\n", *(char **)node->args->ptr);
	if (node->type == _CMD)
	{
		i = 0;
		while (i < node->args->total)
			dprintf(fd, "%s ", ((char **)node->args->ptr)[i++]);
		dprintf(fd, "\n");
	}
}
