/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_mask_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:55:22 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 02:10:14 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "minishelldef.h"
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
			*mask++ = __SQUOTE_MASK;
		else if (interpreter.mode == _DOUBLE && c != '\"')
			*mask++ = __DQUOTE_MASK;
		else
			*mask++ = __NO_MASK;
		c = *mask;
	}
}
