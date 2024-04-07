/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:28:48 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/07 19:32:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>

#include "history.h"
#include "libft.h"
#include "minishelldef.h"

void	add_minishell_history(char *str)
{
	char	*history_file;
	int		fd;

	add_history(str);
	history_file = get_history_filepath();
	if (!history_file)
		return ;
	fd = open(history_file, O_WRONLY | O_CREAT | O_APPEND, 0600);
	free(history_file);
	if (fd == -1)
		return ;
	ft_dprintf(fd, "%s\n", str);
	close(fd);
}

void	load_global_history(void)
{
	char	*history_file;
	int		fd;
	char	*gnl;
	char	*nl;

	history_file = get_history_filepath();
	if (!history_file)
		return ;
	fd = open(history_file, O_RDONLY);
	free(history_file);
	if (fd == -1)
		return ;
	while (!get_next_line(fd, &gnl) && gnl)
	{
		nl = ft_strchr(gnl, '\n');
		if (nl)
			*nl = '\0';
		add_history(gnl);
		free(gnl);
	}
	close(fd);
}

char	*get_history_filepath(void)
{
	char	*home;
	char	*path;

	path = NULL;
	home = getenv("HOME");
	if (home)
	{
		path = ft_sprintf("%s/%s", home, __GLOBAL_HISTORY);
	}
	return (path);
}
