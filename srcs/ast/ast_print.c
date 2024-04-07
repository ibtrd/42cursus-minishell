/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:37:35 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/07 19:37:44 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "ast.h"

static void	print_next_node(int fd, t_astnode *root, int space);
static void	printnode(int fd, t_astnode *node);

void	dprint_ast(int fd, t_astnode *root, char *color)
{
	if (color)
		dprintf(STDERR_FILENO, "\n%s", color);
	else
		dprintf(STDERR_FILENO, "\n");
	print_next_node(fd, root, 0);
	dprintf(STDERR_FILENO,
		"\e[0m\n---------------------------------------------\n");
}

static void	print_next_node(int fd, t_astnode *root, int space)
{
	int	i;

	if (root == NULL)
		return ;
	space += 3;
	print_next_node(fd, root->right, space);
	i = 3;
	while (i++ < space)
		dprintf(fd, " ");
	printnode(fd, root);
	print_next_node(fd, root->left, space);
}

static void	printnode(int fd, t_astnode *node)
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
		while (i++ < (node->args)->total)
		{
			dprintf(fd, "\e[33m|\e[0m%s\e[33m|\e[0m ", (char *)str->ptr);
			str = ft_vector_get(node->args, i);
		}
	}
	dprintf(fd, "\n");
}
