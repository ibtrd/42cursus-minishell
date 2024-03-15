/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:33:54 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/15 18:34:24 by kchillon         ###   ########lyon.fr   */
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
		if (!ft_strcmp(*dir, "-"))
			*dir = ft_getenv(env, "OLDPWD");
	}
	if (!*argv)
		*dir = ft_getenv(env, "HOME");
	return (0);
}

static int	update_wd(t_vector *env)
{
	char	*pwd;
	char	*oldpwd;
	char	*cwd;
	int		error;

	cwd = getcwd(NULL, 0);
	pwd = ft_strjoin("PWD=", cwd);
	free(cwd);
	oldpwd = ft_strjoin("OLDPWD=", ft_getenv(env, "PWD"));
	error = !oldpwd || !pwd || !cwd;
	if (!error)
		error = update_var(env, oldpwd) || update_var(env, pwd);
	free(oldpwd);
	free(pwd);
	return (error);
}

int	builtin_cd(t_executor *exec, char **argv)
{
	char	*dir;

	(void)exec;
	if (!argv)
		return (1);
	dir = NULL;
	if (resolve_dir(&dir, exec->env, argv))
		return (1);
	if (chdir(dir) == -1)
	{
		ft_dprintf(2, "%s: cd: %s: %s\n", __MINISHELL, argv[0], strerror(errno));
		return (1);
	}
	update_wd(exec->env);
	return (0);
}
