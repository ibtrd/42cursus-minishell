/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:32:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/06 16:41:21 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "minishelldef.h"
#include "ast.h"
#include "parsing.h"
#include "testing.h"

int	main(int argc, char **argv, char **env)
{
	t_astnode	*root;

	(void)argc;
	(void)argv;
	(void)env;
	root = commandline_parser("< Makefile cat | (< .gitignore head -c162 && tail)");
	printf("\n\n-------------------\n\n");
	executor(root, env);
	// free(root.args);
	free_ast(root);
	return (0);
}
