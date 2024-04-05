/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:31:06 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/05 20:23:21 by ibertran         ###   ########lyon.fr   */
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
#include "history.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int	check_ttys(void);
static int	init_minishell(t_minishell *minishell, char **old_env, char *sh_name);
static int	minishell_routine(t_minishell *minishell);

int g_signal = 0;

int	main(int ac, char **av, char **env)
{
	t_minishell	minishell;

	(void)ac;
	(void)av;

	if (check_ttys())
		return (1);
	if (init_minishell(&minishell, env, av[0]))
		return (1);
	while (!minishell_routine(&minishell))
		;
	ft_vector_free(&minishell.env);
	rl_clear_history();
	printf("exit\n");
	return (minishell.sp_params.exit_status);
}

static int	minishell_routine(t_minishell *minishell)
{
	char		*input;
	t_astnode	*root;
	int			error;

	error = get_input(minishell, &input);
	if (error)
		return (error == FAILURE);
	root = commandline_parser(input);
	if (create_here_documents(root))
	{
		free_ast(root);
		if (g_signal)
			minishell->sp_params.exit_status = g_signal + 128;
		else
			minishell->sp_params.exit_status = 1;
		return (0);
	}
	minishell->sp_params.exit_status = executor(root, minishell);
	free_ast(root);
	return (0);
}

static int	init_minishell(t_minishell *minishell,
							char **old_env, char *sh_name)
{
	t_vector	env;

	signal_setup_main();
	load_global_history();
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

static int	check_ttys(void)
{
	int	in;
	int	out;

	in = !isatty(STDIN_FILENO);
	if (in)
		ft_dprintf(STDERR_FILENO, "%s: %d: %s\n",
			__MINISHELL,
			STDIN_FILENO,
			__NOT_TTY);
	out = !isatty(STDOUT_FILENO);
	if (out)
		ft_dprintf(STDERR_FILENO, "%s: %d: %s\n",
			__MINISHELL,
			STDOUT_FILENO,
			__NOT_TTY);
	return (in || out);
}
