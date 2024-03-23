/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:43:58 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/22 18:30:53 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "signals.h"

#include <unistd.h>

#include <stdio.h>	// DEBUG

int	exec_init(t_executor *exec, t_astnode *root, t_minishell *minishell)
{
	int	fd;

	exec->minishell = minishell;
	exec->env = &minishell->env;
	exec->pid = 0;
	exec->node = root;
	exec->root = root;
	exec->infd = (t_vector){0};
	exec->outfd = (t_vector){0};
	if (ft_vector_init(&exec->infd, (t_vinfos){sizeof(int), 1, &ft_vclose}))
		return (1);
	if (ft_vector_init(&exec->outfd, (t_vinfos){sizeof(int), 1, &ft_vclose}))
		return (1);
	fd = dup(STDIN_FILENO);
	if (fd == -1)
		return (1);
	if (ft_vector_add(&exec->infd, &fd))
		return (1);
	fd = dup(STDOUT_FILENO);
	if (fd == -1)
		return (1);
	if (ft_vector_add(&exec->outfd, &fd))
		return (1);
	return (0);
}

int	executor(t_astnode *root, t_minishell *minishell)
{
	t_executor	exec;
	int			ret;

	ret = 1;
	if (signal_ign_main())
		return (1);
	if (!exec_init(&exec, root, minishell))
		ret = node_exec(&exec);
	ft_vector_free(&exec.infd);
	ft_vector_free(&exec.outfd);
	signal_setup_main();
	return (ret);
}
