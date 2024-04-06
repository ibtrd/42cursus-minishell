/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:27:36 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/06 17:55:06 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include "libft.h"

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int	open_output(t_executor *exec)
{
	int	fd;

	fd = open(*(char **)ft_vector_get(exec->node->args, 0),
			O_WRONLY | O_CREAT | O_TRUNC,
			0644);
	if (fd == -1)
	{
		ft_dprintf(STDERR_FILENO, __ERR,
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
	return (0);
}
