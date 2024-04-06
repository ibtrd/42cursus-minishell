/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:31:06 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/06 16:37:29 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <unistd.h>
#include <errno.h>

#include "parsing.h"
#include "env.h"
#include "minishelldef.h"
#include "signals.h"
#include "history.h"

int	g_signal = 0;

static int	check_ttys(void)
{
	int	in;
	int	out;

	in = !isatty(STDIN_FILENO);
	if (in)
		ft_dprintf(STDERR_FILENO, __NOT_A_TTY, __MINISHELL, STDIN_FILENO);
	out = !isatty(STDOUT_FILENO);
	if (out)
		ft_dprintf(STDERR_FILENO, __NOT_A_TTY, __MINISHELL, STDOUT_FILENO);
	return (in || out);
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

static int	minishell_routine(t_minishell *minishell)
{
	char		*input;
	t_astnode	*root;
	int			error;

	error = get_input(minishell, &input);
	if (error)
		return (error == EOF);
	root = commandline_parser(input);
	if (!root)
		return (0);
	if (create_here_documents(root))
	{
		free_ast(root);
		if (g_signal)
			minishell->sp_params.exit_status = g_signal + 128;
		else
			minishell->sp_params.exit_status = 1;
		return (0);
	}
	return (executor(root, minishell));
}

int	main(int ac, char **av, char **env)
{
	t_minishell	minishell;

	(void)ac;
	(void)av;
	if (check_ttys())
		return (1);
	if (init_minishell(&minishell, env, av[0]))
	{
		ft_dprintf(STDERR_FILENO, __INIT_ERROR, __MINISHELL, strerror(errno));
		return (1);
	}
	while (!minishell_routine(&minishell))
		;
	ft_vector_free(&minishell.env);
	rl_clear_history();
	printf("exit\n");
	return (minishell.sp_params.exit_status);
}
