/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:34:10 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/22 13:48:24 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include "minishelldef.h"

#include <stdlib.h>
#include <unistd.h>

int	builtin_exit(t_executor *exec, char **argv)
{
	int	status;

	ft_dprintf(2, "exit\n");
	if (!argv || !argv[0])
		status = 0;
	else if (!ft_isnumber(argv[0]))
	{
		ft_dprintf(2, "%s: exit: %s: numeric argument required\n", __MINISHELL, argv[0]);
		status = 2;
	}
	else if (argv[1])
	{
		ft_dprintf(2, "%s: exit: too many arguments\n", __MINISHELL);
		return (1);
	}
	else
		status = (unsigned char)ft_strtol(argv[0], NULL);
	exec_cleanup(exec);
	close(0);
	close(1);
	exit(status);
	return (0);
}
