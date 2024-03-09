/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_mask_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:55:22 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/09 20:45:14 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"
#include "libft.h"

static char	*create_string_mask(char *str);

int	create_interpreter_mask(t_vector *mask, t_vector *args)
{
	char	*str_mask;
	char	**ptr;
	char	**ptr2;
	size_t	i;

	if (ft_vector_init(mask, sizeof(char *), args->capacity))
		return (FAILURE);
	i = 0;
	ptr = ft_vector_get(args, i);
	while (ptr && *ptr)
	{
		if (*ptr)
			str_mask = create_string_mask(*ptr);
		else
			str_mask = NULL;
		if (!str_mask)
		{
			ft_vector_free(mask, ft_vfree);
			return (FAILURE);
		}
		ft_vector_add_ptr(mask, str_mask);
		ptr2 = ft_vector_get(mask, i);
		debug_print_mask(*ptr, *ptr2);
		i++;
		ptr = ft_vector_get(args, i);
	}
	return (SUCCESS);
}
# include "stdio.h" //REMOVE

static char	*create_string_mask(char *str)
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
		mask[i] = interpreter.mode + 48;
		i++;
	}
	return (mask);
}


void	debug_print_mask(char *arg, char *mask)
{
	printf("ARG |%s|\nMASK|%s|\n", arg, mask);
}
