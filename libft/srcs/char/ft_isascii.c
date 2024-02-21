/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:42:40 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/08 19:27:15 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftdef.h"

int	ft_isascii(int c)
{
	if (c >= '\0' && c <= DEL)
		return (1);
	return (0);
}
