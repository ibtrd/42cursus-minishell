/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:08:34 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/19 15:42:18 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishelldef.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

static int	search_here(const char *cmd, char **path)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	if (!tmp)
		return (1);
	if (ft_strcmp(tmp, "/"))
		*path = ft_strjoin2(tmp, "/", cmd);
	else
		*path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!*path)
		return (1);
	if (access(*path, F_OK) == 0)
		return (0);
	free(*path);
	*path = NULL;
	return (1);
}

static int	is_dir(char *path)
{
	struct stat	buf;

	if (stat(path, &buf))
	{
		ft_dprintf(STDERR_FILENO, __ERR, __MINISHELL, path, strerror(errno));
		return (1);
	}
	if (S_ISDIR(buf.st_mode))
		return (1);
	return (0);
}

int	search_path(const char *cmd, char **cmd_path, char *path)
{
	if (!cmd || !*cmd)
		return (1);
	if (path && *path)
	{
		*cmd_path = ft_strtok(path, ":");
		while (*cmd_path)
		{
			*cmd_path = ft_strjoin2(*cmd_path, "/", cmd);
			if (!*cmd_path)
				return (1);
			if (!access(*cmd_path, F_OK) && !is_dir(*cmd_path))
				return (0);
			free(*cmd_path);
			*cmd_path = ft_strtok(NULL, ":");
		}
	}
	else
		return (search_here(cmd, cmd_path));
	return (1);
}
