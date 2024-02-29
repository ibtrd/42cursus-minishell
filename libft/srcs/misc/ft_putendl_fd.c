/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:24:10 by kchillon          #+#    #+#             */
/*   Updated: 2024/02/23 17:27:01 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	if (write(fd, s, len) == -1)
		return (-1);
	return (write(fd, "\n", 1));
}
