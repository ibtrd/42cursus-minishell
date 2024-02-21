/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:31:00 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/15 04:41:27 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	args;
	ssize_t	total_wr;
	ssize_t	wr;
	size_t	i;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	total_wr = 0;
	while (str[i])
	{
		wr = pf_reading_head(fd, str + i, &args);
		if (wr == -1)
			break ;
		total_wr += wr;
		if (str[i] != '%')
			i += wr;
		else
			i += pf_argument_len(str + i + 1);
	}
	va_end(args);
	if (wr == -1)
		return (-1);
	return (total_wr);
}
