/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:30:07 by kchillon          #+#    #+#             */
/*   Updated: 2024/02/23 17:38:11 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell_executor.h"
#include "minishell_def.h"

#include <unistd.h>
#include <fcntl.h>

static int	read_heredoc(char *delimiter)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (!ft_strcmp(line, delimiter))
		{
			free(line);
			break ;
		}
		if (ft_putendl_fd(line, 0) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	return (0);
}

static int	get_heredoc(char *delimiter)
{
	int		fd;
	char	*line;
	char	*path;	

	path = NULL;
	fd = tmp_file(&path, "heredoc");
	if (fd == -1)
		return (-1);
	if (read_heredoc(delimiter))
	{
		unlink(path);
		close(fd);
		free(path);
		return (-1);
	}
	close(fd);
	fd = open(path, O_RDONLY);
	unlink(path);
	free(path);
	return (fd);
}

int	open_heredoc(t_executor *exec)
{
	int	fd;

	fd = get_heredoc(*(char **)ft_vector_get(exec->node->args, 0));
	if (fd == -1)
		return (1);
	if (!dup2(fd, 0))
		return (0);
	close(fd);
	return (1);
}
