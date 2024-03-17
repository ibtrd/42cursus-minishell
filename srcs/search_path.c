/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:08:34 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/17 18:09:44 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>
#include <stdlib.h>

int	search_path(const char *cmd, char **cmd_path, char *path)
{
	if (!path)
		return (1);
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
	return (1);
}
