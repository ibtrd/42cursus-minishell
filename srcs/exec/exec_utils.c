/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:02:17 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/06 18:21:42 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include <stdio.h>

void	printf_redir(t_executor *exec)
{
	size_t	i;

	i = 0;
	dprintf(2, "redir input:\n");
	while (i < exec->infd.total)
	{
		dprintf(2, "%d\n", *(int *)ft_vector_get(&exec->infd, i));
		i++;
	}
	i = 0;
	dprintf(2, "redir output:\n");
	while (i < exec->outfd.total)
	{
		dprintf(2, "%d\n", *(int *)ft_vector_get(&exec->outfd, i));
		i++;
	}
}
