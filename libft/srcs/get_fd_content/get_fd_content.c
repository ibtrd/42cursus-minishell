/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:30:57 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/23 21:10:42 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"

#include <unistd.h>
#include <stdlib.h>

# include <stdio.h>

int	get_fd_content(int fd, char **content)
{
	char		*line;
	// char		line[1000];
	// t_vector	v;
	// int			ret;

	// (void)content;
	dprintf(2, "gfc start\n");
	// ft_memset(line, 0, 1000);
	// read(fd, line, 1000);
	// dprintf(2, "file: |%s|\n", line);
	line = NULL;
	do
	{
		if (get_next_line(fd, &line))
			dprintf(2, "error\n");
		dprintf(2, "%s", line);
		// printf("\n");
		free(line);
	} while (line);
	*content = NULL;
	dprintf(2, "gfc end\n");
	return (0);
}

// int	get_fd_content(int fd, char **content)
// {
// 	char		*line;
// 	t_vector	v;
// 	int			ret;
	
// 	if (ft_vector_init(&v, (t_vinfos){sizeof(char), 0, NULL}))
// 		return (-1);
// 	line = NULL;
// 	ret = get_next_line(fd, &line);
// 	dprintf(2, "ret = %2d\tline: |%s|\n", ret, line);
// 	while (line)
// 	{
// 		ft_vector_strncat(&v, line, ft_strlen(line));
// 		free(line);
// 		ret = get_next_line(fd, &line);
// 		dprintf(2, "ret = %2d\tline: |%s|\n", ret, line);
// 	}
// 	if (ret)
// 	{
// 		ft_vector_free(&v);
// 		return (-1);
// 	}
// 	*content = v.ptr;
// 	return (0);
// }
