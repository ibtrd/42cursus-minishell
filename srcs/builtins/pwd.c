/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:34:06 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/07 18:26:39 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "env.h"
#include "minishelldef.h"
#include "builtins.h"

int	builtin_pwd(t_executor *exec, char **argv)
{
	char	*pwd;

	(void)argv;
	(void)exec;
	pwd = ft_getenv(exec->env, "PWD");
	if (pwd)
	{
		printf("%s\n", pwd);
		return (0);
	}
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_dprintf(STDERR_FILENO, __PWD_ERR, __MINISHELL, strerror(errno));
		return (1);
	}
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
