/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:01:09 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/06 13:34:45 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
# include <testing.h>

static int	open_redirect(t_executor *exec)
{
	static const t_open_redirect	open_redirect[4] = {open_input, \
														open_output, \
														open_input, \
														open_append};
	// int								ret;

	dprintf(2, "open_redirect\n");	// DEBUG
	return (open_redirect[exec->node->type - _INPUT](exec));	// PROTECT
}

// static int	redirect_fork(t_executor *exec, t_astnode *node)
// {
// 	pid_t	pid;
// 	int		status;
// 	int		ret;

// 	if (open_redirect(exec))
// 	{
// 		dprintf(2, "open_redirect failed\n");	// DEBUG
// 		return (1);
// 		// close(0);
// 		// close(1);
// 		// free_ast(exec->root);
// 		// dprintf(2, "end of redirect_fork\n");	// DEBUG
// 	}
// 	dprintf(2, "open_redirect success\n");	// DEBUG
// 	exec->node = node;
// 	ret = node_exec(exec);
// }

int	branch_redirection(t_executor *exec)
{
	t_astnode	*node;
	int			ret;

	dprintf(2, "redirection\n");	// DEBUG
	ret = 0;
	if (open_redirect(exec))
	{
		dprintf(2, "open_redirect failed\n");	// DEBUG
		return (1);
	}	
	dprintf(2, "open_redirect success\n");	// DEBUG
	node = exec->node;
	exec->node = node->right;
	ret = node_exec(exec);
	exec->node = node;
	return (ret);
}
