/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:34:10 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/14 22:00:44 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"
#include "minishelldef.h"

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int	builtin_exit(t_executor *exec, char **argv)
{
	int	status;

	if (isatty(0))
		ft_dprintf(STDERR_FILENO, __MINISHELL_EXIT);
	if (argv && argv[0])
		status = (unsigned char)ft_strtol(argv[0], NULL);
	if (!argv || !argv[0])
		status = exec->minishell->sp_params.exit_status;
	else if (!ft_isnumber(argv[0]) || errno == ERANGE)
	{
		ft_dprintf(STDERR_FILENO, __EXIT_ARGS_ERR, __MINISHELL, argv[0]);
		status = 2;
	}
	else if (argv[1])
	{
		ft_dprintf(STDERR_FILENO, __EXIT_NUMERIC_ERR, __MINISHELL);
		return (1);
	}
	exec_cleanup(exec, 0);
	exit(status);
	return (0);
}
