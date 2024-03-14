/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:41:21 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/12 19:11:17 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include <unistd.h>

#include <stdio.h>

void	close_fds(t_executor *exec)
{
	// size_t	i;

	// i = 0;
	// dprintf(2, "FDIN->total: %zu\n", exec->infd.total);	// DEBUG
	// while (i < exec->infd.total)
	// {
	// 	close(*(int *)ft_vector_get(&exec->infd, i));
	// 	i++;
	// }
	ft_vector_free(&exec->infd);
	// i = 0;
	// dprintf(2, "FDOUT->total: %zu\n", exec->outfd.total);	// DEBUG
	// while (i < exec->outfd.total)
	// {
	// 	close(*(int *)ft_vector_get(&exec->outfd, i));
	// 	i++;
	// }
	ft_vector_free(&exec->outfd);
}