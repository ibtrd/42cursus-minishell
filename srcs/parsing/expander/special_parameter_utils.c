/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_parameter_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:47:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/16 15:43:52 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "expander.h"

#include <stdio.h>

static int	expand_special_param(t_vector *str, size_t index, char *param);

int	is_special_param(t_vector *str, size_t *index, char param, t_minishell *env)
{
	char	*ptr;

	if (param == '?')
		ptr = ft_itoa(env->sp_params.exit_status);
	else if (param == '0')
		ptr = ft_strdup(env->sp_params.sh_name);
	else if (param == '\"' || param == '\'')
	{
		if (!((t_mask *)ft_vector_get(str, *index))->m)
			return (ft_vector_deleten(str, *index, 1));
		else
			(*index)++;
		return (SUCCESS);
	}
	else
	{
		((t_mask *)ft_vector_get(str, *index))->m |= __ENVAR_MASK;
		((t_mask *)ft_vector_get(str, *index + 1))->m |= __ENVAR_MASK;
		return (SUCCESS);
	}
	if (!ptr)
		return (FAILURE);
	return (expand_special_param(str, *index, ptr));
}

static int	expand_special_param(t_vector *str, size_t index, char *param)
{
	const char		m = ((t_mask *)ft_vector_get(str, index))->m | __ENVAR_MASK;
	const size_t	len = ft_strlen(param);
	t_mask			*insert;

	insert = str_to_mask(param, m);
	free(param);
	if (!insert)
		return (FAILURE);
	if (ft_vector_deleten(str, index, 2)
		|| ft_vector_insertn(str, insert, index, len))
	{
		free(insert);
		return (FAILURE);
	}
	free(insert);
	return (SUCCESS);
}
