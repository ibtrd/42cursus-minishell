/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_in_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:10:45 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/14 16:39:05 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_str_in_array(const char *str, const char **array)
{
	int	i;

	if (!str || !array)
		return (-1);
	i = 0;
	while (array[i])
	{
		if (!ft_strcmp(str, array[i]))
			return (i);
		i++;
	}
	return (-1);
}
