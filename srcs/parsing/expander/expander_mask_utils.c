/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_mask_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:55:22 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/05 18:36:06 by ibertran         ###   ########lyon.fr   */
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

char	*mask_to_string(t_vector *arg)
{
	char	*str;
	size_t	i;

	str = malloc(arg->total + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < arg->total)
	{
		str[i] = ((t_mask *)ft_vector_get(arg, i))->c;
		i++;
	}
	str[i] = '\0';
	return (str);
}
