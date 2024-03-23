/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:41:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/23 18:46:28 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "minishelldef.h"
#include "executor.h"

int	builtin_history(t_executor *exec, char **argv)
{
	(void)exec;
	(void)argv;
	unlink(__GLOBAL_HISTORY);
	rl_clear_history();
	return (SUCCESS);
}
