/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:16:43 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/05 20:02:09 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "executor.h"
#include "minishelldef.h"
#include "env.h"
#include "builtins.h"

#include <unistd.h>
#include <errno.h>
#include <string.h>

static int    revert_redirections(t_executor *exec)
{
    if (exec->infd.total > 1)
	{
		if (ft_vector_delete(&exec->infd, exec->infd.total - 1))
			return (1);
		if (dup2(*(int *)ft_vector_get(&exec->infd, exec->infd.total - 1), STDIN_FILENO) != -1)
			return (0);
	}
	if (exec->outfd.total > 1)
	{
		if (ft_vector_delete(&exec->outfd, exec->outfd.total - 1))
			return (1);
		if (dup2(*(int *)ft_vector_get(&exec->outfd, exec->outfd.total - 1), STDOUT_FILENO) != -1)
			return (0);
	}
    ft_dprintf(2, "%s: %s\n", __MINISHELL, strerror(errno));
    return (1);
}

int	exec_builtins(t_executor *exec, int index)
{
	static const t_builtin	builtins[] = {&builtin_echo, &builtin_cd, \
								&builtin_pwd, &builtin_export, &builtin_unset, \
								&builtin_env, &builtin_exit, &builtin_history};
	int							ret;

	if (apply_redirections(exec))
		return (1);
	ret = builtins[index](exec, ft_vector_get(exec->node->args, 1));
	revert_redirections(exec);
	return (ret);
}
