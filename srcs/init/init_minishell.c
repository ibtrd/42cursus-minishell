/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:39:49 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/06 20:47:08 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "env.h"
#include "signals.h"
#include "history.h"

int	init_minishell(t_minishell *minishell, char **old_env, char *sh_name)
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
