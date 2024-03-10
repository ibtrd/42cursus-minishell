/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ffmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:52:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 18:35:35 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

void	*ft_fmalloc(size_t size)
{
	static int	i = 0;
	static int	max = 0;

	if (!max)
	{
		max = size;
		return (NULL);
	}
	if (i++ > max)
	{
		dprintf(2, "Forcing ft_fmalloc() failure! (call^%d)\n", i);
		errno = ENOMEM;
		return (NULL);
	}
	return (malloc(size));
}
