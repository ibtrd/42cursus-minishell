/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:16:43 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/14 16:45:22 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "executor.h"
#include "minishelldef.h"
#include "env.h"
#include "builtins.h"

int	exec_builtins(t_executor *exec, int index)
{
	static const t_builtin	builtins[] = {&builtin_echo, &builtin_cd, &builtin_pwd, \
								&builtin_export, &builtin_unset, &builtin_env, \
								&builtin_exit};
	
	return ((builtins[index])(exec, exec->node->args->ptr));
}
