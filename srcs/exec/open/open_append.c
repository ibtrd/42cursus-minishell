/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:27:36 by kchillon          #+#    #+#             */
/*   Updated: 2024/02/23 14:50:56 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_executor.h"
#include "minishell_def.h"

#include <unistd.h>
#include <fcntl.h>

int	open_append(t_executor *exec)
{
	int	fd;

	fd = open(*(char **)ft_vector_get(exec->node->args, 0), O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (1);
	if (!dup2(fd, 0))
		return (0);
	close(fd);
	return (1);
}
