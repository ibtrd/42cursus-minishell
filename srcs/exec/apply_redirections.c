/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:36:55 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/05 19:43:05 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "executor.h"
#include "minishelldef.h"

#include <unistd.h>
#include <errno.h>
#include <string.h>

# include <stdio.h>

int	apply_redirections(t_executor *exec)
{
	int	fd;

	if (exec->infd.total > 1)
	{
		fd = *(int *)ft_vector_get(&exec->infd, exec->infd.total - 1);
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			ft_dprintf(2, "%s: %s\n", __MINISHELL, strerror(errno));
			return (1);
		}
	}
	if (exec->outfd.total > 1)
	{
		fd = *(int *)ft_vector_get(&exec->outfd, exec->outfd.total - 1);
		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			ft_dprintf(2, "%s: %s\n", __MINISHELL, strerror(errno));
			return (1);
		}
	
	}
	return (0);
}
