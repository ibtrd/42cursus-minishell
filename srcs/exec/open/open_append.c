/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:27:36 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/06 18:22:14 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"

#include <unistd.h>
#include <fcntl.h>

int	open_append(t_executor *exec)
{
	int	fd;
	int	error;

	fd = open(*(char **)ft_vector_get(exec->node->args, 0), O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (1);
	// error = dup2(fd, 1);
	error = ft_vector_add(&exec->outfd, &fd);	// PROTECT
	return (error);
}
