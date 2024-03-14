/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:16:43 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/14 17:04:52 by kchillon         ###   ########lyon.fr   */
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

int	exec_builtins(t_executor *exec, int index)
{
	static const t_builtin	builtins[] = {&builtin_echo, &builtin_cd, &builtin_pwd, \
								&builtin_export, &builtin_unset, &builtin_env, \
								&builtin_exit};
	int							ret;

	ret = dup2(*(int *)ft_vector_get(&exec->infd, exec->infd.total - 1), STDIN_FILENO);
	if (ret != -1)
		ret = dup2(*(int *)ft_vector_get(&exec->outfd, exec->outfd.total - 1), STDOUT_FILENO);
	if (ret == -1)
	{
		ft_dprintf(2, "%s: %s\n", __MINISHELL, strerror(errno));
		return (1);
	}
	ret = builtins[index](exec, exec->node->args->ptr);
	// close(0);
	// close(1);
	return (ret);
}
