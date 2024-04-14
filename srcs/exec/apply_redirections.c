/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:36:55 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/07 19:47:39 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include "minishelldef.h"

#include <errno.h>
#include <string.h>
#include <unistd.h>

int	apply_redirections(t_executor *exec)
{
	int	fd;

	if (exec->infd.total > 1)
	{
		fd = *(int *)ft_vector_get(&exec->infd, exec->infd.total - 1);
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			ft_dprintf(STDERR_FILENO, "%s: %s\n", __MINISHELL, strerror(errno));
			return (1);
		}
	}
	if (exec->outfd.total > 1)
	{
		fd = *(int *)ft_vector_get(&exec->outfd, exec->outfd.total - 1);
		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			ft_dprintf(STDERR_FILENO, "%s: %s\n", __MINISHELL, strerror(errno));
			return (1);
		}
	}
	return (0);
}
