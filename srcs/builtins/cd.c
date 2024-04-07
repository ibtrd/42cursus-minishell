/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:33:54 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/07 18:25:31 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include "env.h"
#include "libft.h"
#include "builtins.h"

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static int	get_dir(char **dir, t_vector *env, char *name)
{
	*dir = ft_getenv(env, name);
	if (!*dir)
	{
		ft_dprintf(STDERR_FILENO, __CD_NOT_SET, __MINISHELL, name);
		return (1);
	}
	return (0);
}

static int	resolve_dir(char **dir, t_vector *env, char **argv)
{
	if (!*argv)
		return (get_dir(dir, env, "HOME"));
	if (argv[1])
	{
		ft_dprintf(STDERR_FILENO, __CD_ARGS, __MINISHELL);
		return (1);
	}
	*dir = argv[0];
	if (ft_strcmp(*dir, "-"))
		return (0);
	return (get_dir(dir, env, "OLDPWD"));
}

static int	update_wd(t_vector *env, char *oldcwd)
{
	char	*pwd;
	char	*cwd;
	char	*oldpwd;
	int		error;

	cwd = getcwd(NULL, 0);
	pwd = ft_strjoin("PWD=", cwd);
	free(cwd);
	oldpwd = ft_strjoin("OLDPWD=", oldcwd);
	free(oldcwd);
	if (errno != ENOMEM)
		error = update_var(env, pwd) | update_var(env, oldpwd);
	else
		error = 0;
	free(oldpwd);
	free(pwd);
	return (error);
}

int	builtin_cd(t_executor *exec, char **argv)
{
	char	*dir;
	char	*oldpwd;

	(void)exec;
	if (!argv)
		return (1);
	dir = NULL;
	if (resolve_dir(&dir, exec->env, argv))
		return (1);
	oldpwd = getcwd(NULL, 0);
	if (chdir(dir) == -1)
	{
		free(oldpwd);
		ft_dprintf(STDERR_FILENO, __CD_ERR,
			__MINISHELL, argv[0], strerror(errno));
		return (1);
	}
	update_wd(exec->env, oldpwd);
	return (0);
}
