/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:32:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/14 18:33:25 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "minishelldef.h"
#include "ast.h"
#include "parsing.h"
#include "testing.h"
#include "env.h"
#include "executor.h"

int	main(int argc, char **argv, char **env)
{
	t_astnode	*root;
	t_vector	envv;

	(void)argc;
	(void)argv;
	(void)env;
	init_env(&envv, env);
	// root = commandline_parser(ft_strdup("< Makefile cat | (head -c162 && tail) > out"), &envv);
	// root = commandline_parser(ft_strdup("echo -nnnn -n -nan oui \"\" non -n > out"), &envv);
	root = commandline_parser(ft_strdup("echo -nnnn -n -nan oui \"\" non -n >> out && < README.md < Makefile cat | (< awd head -c162 < qwjeqjwekq || tail) > out && cata || exit"), &envv);
	printf("\n\n-------------------\n\n");
	// dprint_ast(2, root, NULL); //REMOVE
	executor(root, &envv);
	free_ast(root);
	ft_vector_free(&envv);
	return (0);
}
