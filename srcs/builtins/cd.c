/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:33:54 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/15 17:57:01 by kchillon         ###   ########lyon.fr   */
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

static int	update_wd(t_vector *env)
{
	char	*tmp;
	char	*cwd;

	tmp = ft_strjoin("OLDPWD=", ft_getenv(env, "PWD"));
	if (!tmp || update_var(env, tmp))
		return (1);
	free(tmp);
	cwd = getcwd(NULL, 0);
	tmp = ft_strjoin("PWD=", cwd);
	free(cwd);
	if (!tmp || update_var(env, tmp))
		return (1);
	free(tmp);
	return (0);
}

int	builtin_cd(t_executor *exec, char **argv)
{
	size_t	argc;

	(void)exec;
	if (!argv)
		return (1);
	argc = 0;
	while (argv[argc])
		argc++;
	if (argc > 1)
	{
		ft_dprintf(2, "%s: cd: too many arguments\n", __MINISHELL);
		return (1);
	}
	if (chdir(argv[0]) == -1)
	{
		ft_dprintf(2, "%s: cd: %s: %s\n", __MINISHELL, argv[0], strerror(errno));
		return (1);
	}
	update_wd(exec->env);
	return (0);
}
