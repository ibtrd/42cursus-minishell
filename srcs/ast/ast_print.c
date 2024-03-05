/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:37:35 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/05 13:13:24 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ast.h"

void	dprint_ast(int fd, t_astnode *root)
{
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
		dprintf(fd, "%s\n", *(char **)root->args->ptr);
	}
	dprint_ast(fd, root->right);
}
