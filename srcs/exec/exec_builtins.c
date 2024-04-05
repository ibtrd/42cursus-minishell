/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:16:43 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/05 13:48:03 by kchillon         ###   ########lyon.fr   */
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
	static const t_builtin	builtins[] = {&builtin_echo, &builtin_cd, \
								&builtin_pwd, &builtin_export, &builtin_unset, \
								&builtin_env, &builtin_exit, &builtin_history};
	int							ret;

	ret = builtins[index](exec, ft_vector_get(exec->node->args, 1));
	return (ret);
}
