/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:27:36 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/05 17:44:37 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include "libft.h"

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

# include <stdio.h>

int	open_output(t_executor *exec)
{
	int	fd;

	fd = open(*(char **)ft_vector_get(exec->node->args, 0), O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_dprintf(2, "%s: %s: %s\n",
			__MINISHELL,
			*(char **)ft_vector_get(exec->node->args, 0),
			strerror(errno));
		return (1);
	}
	if (ft_vector_add(&exec->outfd, &fd))
	{
		close(fd);
		return (1);
	}
    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        ft_dprintf(2, "%s: %s\n", __MINISHELL, strerror(errno));
        close(fd);
        exec->outfd.total--;
        return (1);
    }
	return (0);
}
