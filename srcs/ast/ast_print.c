/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:37:35 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/06 00:28:45 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ast.h"

void	dprint_ast(int fd, t_astnode *root)
{
	size_t 	i = 0;

	if (!root)
		return ;
	dprint_ast(fd, root->left);
	if (root->type == _AND)
		dprintf(fd, "&&\n");
	if (root->type == _OR)
		dprintf(fd, "||\n");
	if (root->type == _PIPE)
		dprintf(fd, "|\n");
	if (root->type == _INPUT)
	{
		dprintf(fd, "< %s\n", *(char **)root->args->ptr);
	}
	if (root->type == _OUTPUT)
		dprintf(fd, "> %s\n", *(char **)root->args->ptr);
	if (root->type == _HEREDOC)
		dprintf(fd, "<< %s\n", *(char **)root->args->ptr);
	if (root->type == _APPEND)
		dprintf(fd, ">> %s\n", *(char **)root->args->ptr);
	if (root->type == _CMD)
	{

		while (i < root->args->total)
			dprintf(fd, "%s ", ((char **)root->args->ptr)[i++]);
		dprintf(fd, "\n");
	}
	dprint_ast(fd, root->right);
}
