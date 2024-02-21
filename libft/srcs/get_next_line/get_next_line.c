/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:14:22 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/25 02:55:48 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_read(int fd, t_vector *v, char *buffer);
static int	gnl_join(t_vector *v, char *buffer);
static int	gnl_failure(t_vector *v, char **line);

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	t_vector	v;
	int			status;

	if (fd < 0)
		return (gnl_failure(NULL, line));
	status = ft_vector_init(&v, sizeof(char));
	if (status != SUCCESS)
		return (gnl_failure(NULL, line));
	if (buffer[0])
		status = gnl_join(&v, buffer);
	if (status == FAILURE)
		return (gnl_failure(&v, line));
	else if (status != GNL)
		status = gnl_read(fd, &v, buffer);
	if (status == FAILURE)
		return (gnl_failure(&v, line));
	if (status == GNL || status == SUCCESS)
		ft_vector_trim(&v, v.total + 1);
	*line = v.ptr;
	return (status);
}

static int	gnl_read(int fd, t_vector *v, char *buffer)
{
	ssize_t	rd;
	int		status;

	rd = BUFFER_SIZE;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = '\0';
		if (rd == -1)
			return (FAILURE);
		status = gnl_join(v, buffer);
		if (status != SUCCESS)
			return (status);
	}
	if (!v->total)
		ft_vector_free(v);
	return (GNL_EOF);
}

static int	gnl_join(t_vector *v, char *buffer)
{
	char	*endl;

	endl = ft_strchr(buffer, '\n');
	if (!endl)
		return (ft_vector_join(v, buffer, ft_strlen(buffer)));
	else
	{
		if (ft_vector_join(v, buffer, endl - buffer + 1) == -1)
			return (FAILURE);
		ft_strlcpy(buffer, endl + 1, BUFFER_SIZE);
		return (GNL);
	}
}

static int	gnl_failure(t_vector *v, char **line)
{
	if (v)
		ft_vector_free(v);
	*line = NULL;
	return (FAILURE);
}
