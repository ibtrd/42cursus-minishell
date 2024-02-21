/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:09:05 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/08 19:27:36 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftdef.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c < DEL)
		return (c);
	return (0);
}
