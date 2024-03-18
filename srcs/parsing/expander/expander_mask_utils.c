/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_mask_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:55:22 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/18 02:53:12 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "mask.h"

#include <stdio.h>

t_mask	*str_to_mask(char *str, char mask_value)
{
	const size_t	len = ft_strlen(str);
	t_mask			*insert;
	size_t			i;

	insert = malloc(sizeof(t_mask) * len);
	if (!insert)
		return (NULL);
	i = 0;
	while (i < len)
	{
		(insert + i)->c = *(str + i);
		(insert + i)->m = mask_value;
		i++;
	}
	return (insert);
}
