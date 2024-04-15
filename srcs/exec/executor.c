/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:43:58 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/15 15:43:26 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "signals.h"
#include "minishelldef.h"
#include "libft.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

static int	exec_init(t_executor *exec, t_astnode *root, t_minishell *minishell)
{
	int	fd;

	exec->minishell = minishell;
	exec->env = &minishell->env;
	exec->pid = 0;
	exec->is_main = 1;
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

static int	reopen_std(void)
{
	int	fd;
	int	ret;

	ret = 1;
	if (!isatty(STDIN_FILENO))
	{
		fd = open("/dev/tty", O_RDONLY);
		if (fd == -1)
			return (-1);
		ret = dup2(fd, STDIN_FILENO);
		close(fd);
	}
	if (ret != -1 && !isatty(STDOUT_FILENO))
	{
		fd = open("/dev/tty", O_WRONLY);
		if (fd == -1)
			return (-1);
		ret = dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	if (ret != -1)
		return (1);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	return (-1);
}

// static int	signal_ouput(void)
// {
// 	int	ret;

// 	if (!g_signal)
// 		return (0);
// 	ret = get_col();
// 	if (ret == -1)
// 	{
// 		ft_dprintf(STDERR_FILENO, __ERRTERMIOS, __MINISHELL, strerror(errno));
// 		return (SUCCESS);
// 	}
// 	if (ret < -1)
// 		return (FAILURE);
// 	if (ret == 1)
// 		return (SUCCESS);
// 	if (g_signal == SIGQUIT)
// 		printf(__QUIT);
// 	printf("\n");
// 	return (SUCCESS);
// }

int	executor(t_astnode *root, t_minishell *minishell)
{
	t_executor	exec;
	int			ret;

	g_signal = 0;
	ret = 1;
	signal_setup_exec();
	if (!exec_init(&exec, root, minishell))
		ret = node_exec(&exec);
	if (ret & 0x100)
		ret = reopen_std();
	minishell->sp_params.exit_status = get_exit_status(ret);
	if (ret == -1)
		minishell->sp_params.exit_status = 1;
	// ret = signal_ouput();
	ft_vector_free(&exec.infd);
	ft_vector_free(&exec.outfd);
	free_ast(root);
	signal_setup_main();
	return (ret == FAILURE);
}
