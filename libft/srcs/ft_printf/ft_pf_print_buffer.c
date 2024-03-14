/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:26:21 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/12 15:30:54 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>

#include "ft_vector.h"

int	print_buffer(int fd, t_vector *buffer)
{
	ssize_t	status;

	status = write(fd, buffer->ptr, buffer->total);
	ft_vector_free(buffer);
	return (status);
}
