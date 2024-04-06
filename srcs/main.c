/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:31:06 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/06 20:50:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <unistd.h>
#include <errno.h>

#include "env.h"
#include "init.h"
#include "minishelldef.h"

int	g_signal = 0;

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
	while (!interpreter_routine(&minishell, *env))
		;
	ft_vector_free(&minishell.env);
	rl_clear_history();
	printf(__MINISHELL_EXIT);
	return (minishell.sp_params.exit_status);
}
