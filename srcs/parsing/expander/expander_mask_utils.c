/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_mask_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:55:22 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 04:12:55 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "interpreter.h"
#include "expander.h"

int	create_interpreter_masks(t_vector *mask, t_vector *args)
{
	char	*str_mask;
	char	**ptr;
	size_t	i;

	if (ft_vector_init(mask, sizeof(char *), args->capacity))
		return (FAILURE);
	i = 0;
	ptr = ft_vector_get(args, i);
	while (ptr && *ptr)
	{
		str_mask = create_string_mask(*ptr);
		if (!str_mask)
		{
			ft_vector_free(mask, ft_vfree);
			return (FAILURE);
		}
		ft_vector_add_ptr(mask, str_mask);
		i++;
		ptr = ft_vector_get(args, i);
	}
	return (SUCCESS);
}

char	*create_string_mask(char *str)
{
	char		*mask;
	t_escape	interpreter;
	size_t		i;

	mask = ft_strdup(str);
	if (!mask)
		return (NULL);
	init_escape(&interpreter);
	i = 0;
	while (mask[i])
	{
		set_escape_mode(&interpreter, mask[i]);
		if (interpreter.mode == _SINGLE && mask[i] != '\'')
			mask[i] = '\'';
		else if (interpreter.mode == _DOUBLE && mask[i] != '\"')
			mask[i] = '\"';
		else
			mask[i] = '.';
		i++;
	}
	return (mask);
}
