/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_vectors_to_strings.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:25:47 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 02:26:03 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ast.h"

int	args_vectors_to_stings(t_vector **args, t_nodetype node)
{
	t_vector	*strings;
	char		*str;
	size_t		i;

	if (ft_vector_alloc(&strings, (t_vinfos){sizeof(char *), (*args)->total + (node == _CMD), ft_vfree}, 1))
		return (FAILURE);
	i = 0;
	while (i < (*args)->total)
	{
		str = ((t_vector *)ft_vector_get(*args, i))->ptr;
		str = ft_strdup(str);
		if (!str)
		{
			ft_vector_free(strings);
			return (FAILURE);
		}
		ft_vector_add_ptr(strings, str);
		i++;
	}
	ft_vector_dealloc(args, 1);
	*args = strings;
	return (SUCCESS);
}
