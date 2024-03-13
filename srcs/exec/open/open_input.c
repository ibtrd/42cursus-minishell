/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:27:36 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/13 20:54:50 by kchillon         ###   ########lyon.fr   */
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

int	open_input(t_executor *exec)
{
	int	fd;

	fd = open(*(char **)ft_vector_get(exec->node->args, 0), O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(2, "%s: %s: %s\n",
			__MINISHELL,
			*(char **)ft_vector_get(exec->node->args, 0),
			strerror(errno));
		return (1);
	}
	if (ft_vector_add(&exec->infd, &fd))
	{
		close(fd);
		return (1);
	}
	// dprintf(2, "AAAAAAAAAAAAA");	// DEBUG
	// dprintf(2, "file = %s\t", *(char **)ft_vector_get(exec->node->args, 0));	// DEBUG
	// dprintf(2, "fd = %d\n", fd);	// DEBUG
	return (0);
}
