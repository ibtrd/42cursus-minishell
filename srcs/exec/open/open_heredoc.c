/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:27:36 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/02 23:17:51 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include "libft.h"

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

# include <stdio.h>

static int	get_heredoc(t_executor *exec)
{
	int		fd;
	char	*path;
	int		ret;

	path = NULL;
	fd = ft_tmp_file(&path, "heredoc");
	if (fd == -1)
		return (-1);
	ret = write(fd, (char *)ft_vector_get(exec->node->args, 0), exec->node->args->total);
	close(fd);
	if (ret != -1)
		fd = open(path, O_RDONLY);
	unlink(path);
	free(path);
	if (ret == -1 || fd == -1)
		return (-1);
	return (fd);
}

int	open_heredoc(t_executor *exec)
{
	int	fd;

	fd = get_heredoc(exec);
	if (fd == -1)
	{
		ft_dprintf(2, "%s: heredoc: %s\n",
			__MINISHELL,
			strerror(errno));
		return (1);
	}
    if (dup2(fd, STDIN_FILENO) == -1)
    {
        ft_dprintf(2, "%s: %s\n", __MINISHELL, strerror(errno));
        close(fd);
        return (1);
    }
    if (ft_vector_add(&exec->infd, &fd))
    {
        close(fd);
        dup2(*(int *)ft_vector_get(&exec->infd, exec->infd.total - 1), STDIN_FILENO); // ERROR ANYWAY
        return (1);
    }
	return (0);
}
