/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:33:54 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/15 21:06:11 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include "env.h"
#include "libft.h"

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static int	resolve_dir(char **dir, t_vector *env, char **argv)
{
	size_t	argc;

	if (argv && *argv)
	{
		argc = 0;
		while (argv[argc])
			argc++;
		if (argc > 1)
		{
			ft_dprintf(2, "%s: cd: too many arguments\n", __MINISHELL);
			return (1);
		}
		*dir = argv[0];
		if (ft_strcmp(*dir, "-"))
			return (0);
		*dir = ft_getenv(env, "OLDPWD");
		if (!*dir)
		{
			ft_dprintf(2, "%s: cd: OLDPWD not set\n", __MINISHELL);
			return (1);
		}
	}
	if (!*argv)
		*dir = ft_getenv(env, "HOME");
	return (0);
}

#include <stdio.h>

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
		error = update_var(env, oldpwd) || update_var(env, pwd);
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
	if (!oldpwd)
		return (1);
	if (chdir(dir) == -1)
	{
		free(oldpwd);
		ft_dprintf(2, "%s: cd: %s: %s\n", __MINISHELL, argv[0], strerror(errno));
		return (1);
	}
	update_wd(exec->env, oldpwd);
	return (0);
}
