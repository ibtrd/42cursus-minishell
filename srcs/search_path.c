/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:08:34 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/20 21:11:50 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>
#include <stdlib.h>

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

int	search_path(const char *cmd, char **cmd_path, char *path)
{
	if (path && *path)
	{
		*cmd_path = ft_strtok(path, ":");
		while (*cmd_path)
		{
			*cmd_path = ft_strjoin2(*cmd_path, "/", cmd);
			if (!*cmd_path)
				return (1);
			if (access(*cmd_path, F_OK) == 0)
				return (0);
			free(*cmd_path);
			*cmd_path = ft_strtok(NULL, ":");
		}
	}
	else
		return (search_here(cmd, cmd_path));
	return (1);
}
