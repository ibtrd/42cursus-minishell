/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:28:48 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/25 15:41:02 by ibertran         ###   ########lyon.fr   */
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
	char	*nl;

	fd = open(__GLOBAL_HISTORY, O_RDONLY);
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
	//ADD ERROR MESSAGE
}
