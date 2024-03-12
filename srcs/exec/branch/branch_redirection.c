/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:01:09 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/12 18:58:02 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
# include <testing.h>

static int	open_redirect(t_executor *exec)
{
	static const t_open_redirect	open_redirect[4] = {open_input, \
														open_output, \
														open_input, \
														open_append};
	// int								ret;

	// dprintf(2, "open_redirect\n");	// DEBUG
	return (open_redirect[exec->node->type - _INPUT](exec));	// PROTECT
}

static int	close_redirect(t_executor *exec)
{
	if (exec->node->type == _INPUT || exec->node->type == _HEREDOC)
	{
		// dprintf(2, "close_redirect input\n");	// DEBUG
		// dprintf(2, "\tfd = %d\n", *(int *)ft_vector_get(exec->redir + __FDIN, (exec->redir + __FDIN)->total - 1));	// DEBUG
		close(*(int *)ft_vector_get(&exec->infd, exec->infd.total - 1));
		ft_vector_delete(&exec->infd, exec->infd.total - 1, NULL);
	}
	else if (exec->node->type == _OUTPUT || exec->node->type == _APPEND)
	{
		// dprintf(2, "close_redirect output\n");	// DEBUG
		// dprintf(2, "\tfd = %d\n", *(int *)ft_vector_get(exec->redir + __FDOUT, (exec->redir + __FDOUT)->total - 1));	// DEBUG
		close(*(int *)ft_vector_get(&exec->outfd, exec->outfd.total - 1));
		ft_vector_delete(&exec->outfd, exec->outfd.total - 1, NULL);
	}
	return (0);
}

int	branch_redirection(t_executor *exec)
{
	t_astnode	*node;
	int			ret;

	// dprintf(2, "redirection\n");	// DEBUG
	ret = 0;
	if (open_redirect(exec))
	{
		dprintf(2, "open_redirect failed\n");	// DEBUG
		dprintf(2, "Node Type: %d\n", exec->node->type);	// DEBUG
		dprintf(2, "%s: %s\n", *(char **)ft_vector_get(exec->node->args, 0), strerror(errno));	// DEBUG
		return (1);
	}	
	// dprintf(2, "open_redirect success\n");	// DEBUG
	node = exec->node;
	exec->node = node->right;
	ret = node_exec(exec);
	exec->node = node;
	printf_redir(exec);	// DEBUG
	if (close_redirect(exec))
	{
		dprintf(2, "close_redirect failed\n");	// DEBUG
		return (1);
	}
	return (ret);
}
