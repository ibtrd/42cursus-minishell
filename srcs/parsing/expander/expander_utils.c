/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:05:32 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 04:18:07 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

#include "libft.h"

int	init_expansion_vectors(t_vector expanded[2], char *str, char *mask)
{
	const size_t	len = ft_strlen(str);

	if (ft_vector_init(expanded, sizeof(char), len << 1))
		return (FAILURE);
	if (ft_vector_init(expanded + 1, sizeof(char), len << 1))
	{
		ft_vector_free(expanded, NULL);
		return (FAILURE);
	}
	if (ft_vector_join(expanded, str, len + 1)
		|| ft_vector_join(expanded + 1, mask, len + 1))
	{
		ft_vector_free(expanded, NULL);
		ft_vector_free(expanded + 1, NULL);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	remove_var_names(t_vector expanded[2], size_t index, char *name)
{
	const size_t	len = ft_strlen(name) + 1;

	if (ft_vector_deleten(expanded, index, len, NULL)
		|| ft_vector_deleten(expanded + 1, index, len, NULL))
	{
		free(name);
		ft_vector_free(expanded, NULL);
		ft_vector_free(expanded + 1, NULL);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	insert_var_values(t_vector expanded[2], size_t *index, char *value)
{
	const size_t	len = ft_strlen(value);
	char			*mask_insert;

	mask_insert = malloc(sizeof(char) * len);
	if (!mask_insert)
	{
		ft_vector_free(expanded, NULL);
		ft_vector_free(expanded + 1, NULL);
		return (FAILURE);
	}
	ft_memset(mask_insert, '$', len);
	if (ft_vector_insertn(expanded, value, *index, len)
		|| ft_vector_insertn(expanded + 1, mask_insert, *index, len))
	{
		free(mask_insert);
		ft_vector_free(expanded, NULL);
		ft_vector_free(expanded + 1, NULL);
		return (FAILURE);
	}
	free(mask_insert);
	*index += len;
	return (SUCCESS);
}

int	replace_vector_pointers(char **ptr, char **mask, t_vector expanded[2])
{
	free(*ptr);
	*ptr = ft_vector_get(expanded, 0);
	free(*mask);
	*mask = ft_vector_get(expanded + 1, 0);
	return (SUCCESS);
}
