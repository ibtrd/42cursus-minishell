/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:37:35 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/28 20:47:22 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ast.h"

void	print_ast(t_astnode *root)
{
	if (!root)
		return ;
	print_ast(root->left);
	if (root->type == _AND)
		printf("&&\n");
	if (root->type == _OR)
		printf("||\n");
	if (root->type == _PIPE)
		printf("|\n");
	if (root->type == _INPUT)
		printf("<\n");
	if (root->type == _OUTPUT)
		printf(">\n");
	if (root->type == _HEREDOC)
		printf("<<\n");
	if (root->type == _APPEND)
		printf(">>\n");
	if (root->type == _CMD)
	{
		printf("%s\n", (char *)root->args->ptr);
	}
	print_ast(root->right);
}
