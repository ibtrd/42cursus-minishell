/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:31:06 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/23 22:05:45 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>

#include "ast.h"
#include "parsing.h"
#include "executor.h"
#include "env.h"
#include "minishelldef.h"
#include "minishell.h"
#include "signals.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int	init_minishell(t_minishell *minishell, char **old_env, char *sh_name)
{
	t_vector	env;

	if (signal_setup_main())
		return (1);
	if (init_env(&env, old_env))
		return (1);
	minishell->env = env;
	minishell->sp_params.exit_status = 0;
	if (sh_name)
		minishell->sp_params.sh_name = sh_name;
	else
		minishell->sp_params.sh_name = __MINISHELL;
	return (0);
}

static int	minishell_routine(t_minishell *minishell)
{
	char		*input;
	t_astnode	*root;

	if (get_input(minishell, &input))
		return (1);
	root = commandline_parser(input);
	minishell->sp_params.exit_status = executor(root, minishell);
	free_ast(root);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_minishell	minishell;

	(void)ac;
	(void)av;
	if (!isatty(STDIN_FILENO))
		return (0);
	if (init_minishell(&minishell, env, av[0]))
		return (1);
	while (!minishell_routine(&minishell))
		;
	ft_vector_free(&minishell.env);
	rl_clear_history();
	printf("exit\n");
	return (minishell.sp_params.exit_status);
}
