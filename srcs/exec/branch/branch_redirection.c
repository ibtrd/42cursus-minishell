/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:01:09 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/14 17:57:35 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include "libft.h"

#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

# include <stdio.h>
# include <testing.h>

static int	open_redirect(t_executor *exec)
{
	static const t_open_redirect	open_redirect[4] = {open_input, \
														open_output, \
														open_input, \
														open_append};

	return (open_redirect[exec->node->type - _INPUT](exec));
}

static int    close_redirect(t_executor *exec)
{
    if (exec->node->type == _INPUT || exec->node->type == _HEREDOC)
    {
        if (ft_vector_delete(&exec->infd, exec->infd.total - 1))
            return (1);
        if (dup2(*(int *)ft_vector_get(&exec->infd, exec->infd.total - 1), STDIN_FILENO) != -1)
            return (0);
    }
    else if (exec->node->type == _OUTPUT || exec->node->type == _APPEND)
    {
        if (ft_vector_delete(&exec->outfd, exec->outfd.total - 1))
            return (1);
        if (dup2(*(int *)ft_vector_get(&exec->outfd, exec->outfd.total - 1), STDOUT_FILENO) != -1)
            return (0);
    }
    ft_dprintf(2, "%s: %s\n", __MINISHELL, strerror(errno));
    return (1);
}

int	branch_redirection(t_executor *exec)
{
	t_astnode	*node;
	int			ret;

	ret = 0;
	if (open_redirect(exec))
	{
		return (1);
	}
	node = exec->node;
	exec->node = node->right;
	ret = node_exec(exec);
	exec->node = node;
	if (close_redirect(exec))
	{
		return (1);
	}
	return (ret);
}
