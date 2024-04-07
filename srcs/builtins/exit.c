/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:34:10 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/07 18:26:01 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include "minishelldef.h"
#include "builtins.h"

#include <stdlib.h>
#include <unistd.h>

int	builtin_exit(t_executor *exec, char **argv)
{
	int	status;

	ft_dprintf(STDERR_FILENO, __MINISHELL_EXIT);
	if (!argv || !argv[0])
		status = 0;
	else if (!ft_isnumber(argv[0]))
	{
		ft_dprintf(STDERR_FILENO, __EXIT_ARGS_ERR, __MINISHELL, argv[0]);
		status = 2;
	}
	else if (argv[1])
	{
		ft_dprintf(STDERR_FILENO, __EXIT_NUMERIC_ERR, __MINISHELL);
		return (1);
	}
	else
		status = (unsigned char)ft_strtol(argv[0], NULL);
	exec_cleanup(exec, 0);
	exit(status);
	return (0);
}
