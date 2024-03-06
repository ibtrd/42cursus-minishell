/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:32:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/06 14:45:55 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "minishelldef.h"
#include "ast.h"
#include "parsing.h"
#include "testing.h"

t_astnode	*ast_test3(void)
{
	t_astnode	*a;
	t_astnode	*b;
	t_astnode	*c;
	t_astnode	*d;
	t_astnode	*e;
	t_astnode	*f;
	t_astnode	*g;
	t_astnode	*h;
	t_astnode	*root = NULL;

	// char 		str1[] =  "echo oui";
	// char 		str2[] =  "../push_swap/push_swap 1 3 2";
	// char 		str3[] =  "../push_swap/checker 1 3 2";

//	ft_vector_init(); ----------------------------------------------------------

	t_vector	*v1 = malloc(sizeof(t_vector));
	ft_vector_init(v1, sizeof(char *), 0);
	
	ft_vector_add_ptr(v1, "Makefile");
	// ft_vector_add_ptr(v1, "oui");
	ft_vector_add_ptr(v1, NULL);


	t_vector	*v2 = malloc(sizeof(t_vector));
	ft_vector_init(v2, sizeof(char *), 0);
	
	ft_vector_add_ptr(v2, "cat");
	// ft_vector_add_ptr(v2, "-n5");
	ft_vector_add_ptr(v2, NULL);


	// t_vector	*v3 = malloc(sizeof(t_vector));
	// ft_vector_init(v3, sizeof(char *), 0);
	
	// // ft_vector_add_ptr(v3, "|");
	// ft_vector_add_ptr(v3, NULL);


	t_vector	*v4 = malloc(sizeof(t_vector));
	ft_vector_init(v4, sizeof(char *), 0);

	ft_vector_add_ptr(v4, "head");
	ft_vector_add_ptr(v4, "-c162");
	ft_vector_add_ptr(v4, NULL);


	t_vector	*v5 = malloc(sizeof(t_vector));
	ft_vector_init(v5, sizeof(char *), 0);

	ft_vector_add_ptr(v5, "tail");
	ft_vector_add_ptr(v5, NULL);


	t_vector	*v6 = malloc(sizeof(t_vector));
	ft_vector_init(v6, sizeof(char *), 0);
	
	ft_vector_add_ptr(v6, "out1");
	ft_vector_add_ptr(v6, NULL);


	t_vector	*v7 = malloc(sizeof(t_vector));
	ft_vector_init(v7, sizeof(char *), 0);
	
	ft_vector_add_ptr(v7, "out2");
	ft_vector_add_ptr(v7, NULL);

//	ast_newnode(); -------------------------------------------------------------

	ast_newnode(&a, _INPUT, v1);
	ast_newnode(&b, _CMD, v2);
	ast_newnode(&c, _PIPE, NULL);
	ast_newnode(&d, _CMD, v4);
	ast_newnode(&e, _AND, NULL);
	ast_newnode(&f, _CMD, v5);
	ast_newnode(&g, _OUTPUT, v6);
	ast_newnode(&h, _OUTPUT, v7);

//	ast_addnode(); -------------------------------------------------------------

	root = ast_addnode(root, a);
	root = ast_addnode(root, b);
	root = ast_addnode(root, c);
	g->right = root;
	root = g;

	h->right = d;
	e->left = h;
	e->right = f;
	c->right = e;
	// root = ast_addnode(root, d);
	// root = ast_addnode(root, e);
	// root = ast_addnode(root, f);

	// a->left = b;
	// a->right = c;
	// c->left = d;
	// c->right = e;
	return (root);
}

int	main(int argc, char **argv, char **env)
{
	t_astnode	*root;

	(void)argc;
	(void)argv;
	(void)env;
	root = ast_test3();
	dprint_ast(2, root);
	executor(root, env);
	// free(root.args);
	free_ast(root);
	return (0);
}
