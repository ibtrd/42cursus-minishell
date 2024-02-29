/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_test1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:31:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/29 19:11:01 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "ast.h"
#include "libft.h"

t_astnode	*ast_test1(void)
{
	t_astnode	*a;
	t_astnode	*b;
	t_astnode	*c;
	t_astnode	*d;
	t_astnode	*e;
	t_astnode	*f;
	t_astnode	*root = NULL;

	int			i;
	char 		str1[] =  "make -C ../push_swap";
	char 		str2[] =  "../push_swap/push_swap 1 3 2";
	char 		str3[] =  "../push_swap/checker 1 3 2";

	t_vector	*v1 = malloc(sizeof(t_vector));
	ft_vector_init(v1, sizeof(char), 0);
	i = 0;
	while (str1[i])
		ft_vector_add(v1, str1 + i++);
	ft_vector_add(v1, "\0");

	t_vector	*v2 = malloc(sizeof(t_vector));
	ft_vector_init(v2, sizeof(char), 0);
	i = 0;
	while (str2[i])
		ft_vector_add(v2, str2 + i++);
	ft_vector_add(v2, "\0");

	t_vector	*v3 = malloc(sizeof(t_vector));
	ft_vector_init(v3, sizeof(char), 0);
	i = 0;
	while (str3[i])
		ft_vector_add(v3, str3 + i++);
	ft_vector_add(v3, "\0");

	ast_newnode(&a, _CMD, v1);
	ast_newnode(&b, _AND, NULL);
	ast_newnode(&c, _CMD, v2);
	ast_newnode(&d, _PIPE, NULL);
	ast_newnode(&e, _CMD, v3);
	ast_newnode(&f, _APPEND, v1);

	root = ast_addnode(root, a);
	root = ast_addnode(root, b);
	root = ast_addnode(root, c);
	root = ast_addnode(root, d);
	root = ast_addnode(root, e);
	root = ast_addnode(root, f);

	// a->left = b;
	// a->right = c;
	// c->left = d;
	// c->right = e;
	return (root);
}

	// t_astnode	*a;
	// t_astnode	*b;
	// t_astnode	*c;
	// t_astnode	*d;
	// t_astnode	*e;

	// ast_newnode(&a, _AND, NULL);
	// ast_newnode(&b, _CMD, ft_split("make -C ../push_swap", ' '));
	// ast_newnode(&c, _PIPE, NULL);
	// ast_newnode(&d, _CMD, ft_split("../push_swap/push_swap 1 3 2", ' '));
	// ast_newnode(&e, _CMD, ft_split("../push_swap/checker 1 3 2", ' '));
	// a->left = b;
	// a->right = c;
	// c->left = d;
	// c->right = e;