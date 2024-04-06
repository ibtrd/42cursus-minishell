/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:16:43 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/06 17:40:22 by ibertran         ###   ########lyon.fr   */
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

static int	revert_redirections(t_executor *exec)
{
	int	ret;

	ret = 0;
	if (exec->infd.total > 1)
	{
		ret = ft_vector_delete(&exec->infd, exec->infd.total - 1) == FAILURE;
		if (!ret)
			ret = dup2(*(int *)(exec->infd.ptr + (exec->infd.total - 1)),
					STDIN_FILENO) == FAILURE;
	}
	ret <<= 1;
	if (exec->outfd.total > 1)
	{
		ret += ft_vector_delete(&exec->outfd, exec->outfd.total - 1) == FAILURE;
		if (!(ret & 1))
			ret += dup2(*(int *)(exec->outfd.ptr + (exec->outfd.total - 1)),
					STDOUT_FILENO) == FAILURE;
	}
	if (ret)
		ft_dprintf(STDERR_FILENO, "%s: %s\n", __MINISHELL, strerror(errno));
	return (ret);
}

int	exec_builtins(t_executor *exec, int index)
{
	static const t_builtin	builtins[] = {&builtin_echo, &builtin_cd, \
								&builtin_pwd, &builtin_export, &builtin_unset, \
								&builtin_env, &builtin_exit, &builtin_history};
	int						ret;

	if (apply_redirections(exec))
		return (1);
	ret = builtins[index](exec, ft_vector_get(exec->node->args, 1));
	if (revert_redirections(exec))
		return (257);
	return (ret);
}
