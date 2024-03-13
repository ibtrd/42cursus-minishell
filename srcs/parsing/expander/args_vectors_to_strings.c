/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_vectors_to_strings.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:25:47 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/13 11:52:58 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "ast.h"
#include "mask.h"

static char	*mask_to_string(t_vector *arg);

int	args_vectors_to_stings(t_vector **args)
{
	t_vector	*strings;
	char		*str;
	size_t		i;

	if (ft_vector_alloc(&strings,
			(t_vinfos){sizeof(char *), (*args)->total + 1, ft_vfree}, 1))
		return (FAILURE);
	i = 0;
	while (i < (*args)->total)
	{
		str = mask_to_string(((t_vector *)ft_vector_get(*args, i)));
		if (!str)
		{
			ft_vector_dealloc(&strings, 1);
			return (FAILURE);
		}
		ft_vector_add_ptr(strings, str);
		i++;
	}
	ft_vector_add_ptr(strings, NULL);
	ft_vector_printi(strings, ft_vprint_str, "STRING");
	ft_vector_dealloc(args, 1);
	*args = strings;
	return (SUCCESS);
}

static char	*mask_to_string(t_vector *arg)
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
