/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:28:48 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/23 21:08:00 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <readline/history.h>

#include <libft.h>

#include "minishelldef.h"

void	minishell_add_history(char *str)
{
	int		fd;

	add_history(str);
	fd = open(__GLOBAL_HISTORY, O_WRONLY | O_CREAT | O_APPEND, 0600);
	if (fd == -1)
		return ;
	ft_dprintf(fd, "%s\n", str);
	close(fd);
}

void	load_global_history(void)
{
	int		fd;
	char	*gnl;
	char	*line;

	fd = open(__GLOBAL_HISTORY, O_RDONLY);
	if (fd == -1)
		return ;
	while (!get_next_line(fd, &gnl) && gnl)
	{
		line = ft_strndup(gnl, ft_strlen(gnl) - 1);
		free(gnl);
		if (!line)
		{
			close(fd);
			return ;
		}
		add_history(line);
		free(line);
	}
	close(fd);
	//ADD ERROR MESSAGE
}
