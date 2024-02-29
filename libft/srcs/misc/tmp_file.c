/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:51:07 by kchillon          #+#    #+#             */
/*   Updated: 2024/02/23 16:45:46 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

static char	*generate_tmp_filepath(char *prefix)
{
	char	*tmp_name;
	char	*path;

	tmp_name = generate_rand_str(10, ALPHANUM);
	if (!tmp_name)
		return (NULL);
	path = ft_strjoin2("/tmp/", prefix, tmp_name);
	free(tmp_name);
	if (!path)
		return (NULL);
	return (path);
}

int	tmp_file(char **path, char *prefix)
{
	int		fd;
	int		i;

	*path = NULL;
	i = 0;
	fd = 0;
	while (errno == EEXIST && i < 1000 || fd == -1)
	{
		free(*path);
		*path = generate_tmp_filepath(prefix);
		if (!*path)
			return (-1);
		fd = open(*path, O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 0644);
		i++;
	}
	if (i > 1000 || fd == -1)
	{
		free(*path);
		return (-1);
	}
	return (fd);
}
