/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_mask_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:55:22 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/11 03:07:38 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "interpreter.h"
#include "expander.h"
#include "ast.h"

static int	create_interpretation_mask(t_vector *masks, char *str);
static void	set_interpretation_mask(char *mask);

int	init_interpretation_masks(t_vector *masks, t_vector *args)
{
	t_vector	*str;
	size_t		i;

	if (ft_vector_init(masks, (t_vinfos){sizeof(t_vector), args->capacity, &del_args}))
		return (FAILURE);
	i = 0;
	while (i < args->total)
	{
		str = ft_vector_get(args, i);
		if (create_interpretation_mask(masks, (char *)str->ptr))
		{
			ft_vector_free(masks);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

static int	create_interpretation_mask(t_vector *vector, char *str)
{
	const size_t	len = ft_strlen(str) + 1;
	t_vector		mask;

	if (ft_vector_init(&mask, (t_vinfos){sizeof(char), len, NULL}))
		return (FAILURE);
	if (ft_vector_join(&mask, str, len) || ft_vector_add(vector, &mask))
	{
		ft_vector_free(&mask);
		return (FAILURE);
	}
	set_interpretation_mask((char *)mask.ptr);
	return (SUCCESS);
}

static void	set_interpretation_mask(char *mask)
{
	t_escape	interpreter;
	char		c;

	init_escape(&interpreter);
	c = *mask;
	while (c)
	{
		set_escape_mode(&interpreter, c);
		if (interpreter.mode == _SINGLE && c != '\'')
			*mask++ = '\'';
		else if (interpreter.mode == _DOUBLE && c != '\"')
			*mask++ = '\"';
		else
			*mask++ = '.';
		c = *mask;
	}
}

// char	*create_string_mask(char *str)
// {
// 	char		*mask;
// 	t_escape	interpreter;
// 	size_t		i;

// 	mask = ft_strdup(str);
// 	if (!mask)
// 		return (NULL);
// 	init_escape(&interpreter);
// 	i = 0;
// 	while (mask[i])
// 	{
// 		set_escape_mode(&interpreter, mask[i]);
// 		if (interpreter.mode == _SINGLE && mask[i] != '\'')
// 			mask[i] = '\'';
// 		else if (interpreter.mode == _DOUBLE && mask[i] != '\"')
// 			mask[i] = '\"';
// 		else
// 			mask[i] = '.';
// 		i++;
// 	}
// 	return (mask);
// }
