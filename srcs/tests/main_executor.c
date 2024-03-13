/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:32:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/13 18:30:39 by kchillon         ###   ########lyon.fr   */
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
	root = commandline_parser(ft_strdup("< README.md < Makefile cat | (< .gitignore head -c162 && tail)"), &envv);
	printf("\n\n-------------------\n\n");
	dprint_ast(2, root, NULL); //REMOVE
	executor(root, &envv);
	// free(root.args);
	return (0);
}
