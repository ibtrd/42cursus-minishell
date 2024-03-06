/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:41:21 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/06 13:49:11 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include <unistd.h>

void	close_fds(t_executor *exec)
{
	size_t	i;

	i = 0;
	while (i < (exec->redir + __FDIN)->total)
	{
		close(*(int *)ft_vector_get(exec->redir + __FDIN, i));
		i++;
	}
	ft_vector_free(exec->redir + __FDIN, NULL);
	i = 0;
	while (i < (exec->redir + __FDOUT)->total)
	{
		close(*(int *)ft_vector_get(exec->redir + __FDOUT, i));
		i++;
	}
	ft_vector_free(exec->redir + __FDOUT, NULL);
}