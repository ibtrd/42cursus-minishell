/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:21:50 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/14 20:08:24 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*ft_getenv(t_vector *env, char *name)
{
	size_t		i;
	size_t		entry_len;
	size_t		name_len;

	if (!env || !name)
		return (NULL);
	name_len = ft_strlen(name);
	i = 0;
	while (i < env->total - 1)
	{
		entry_len = ft_strlen_charset(*(char **)ft_vector_get(env, i), "=");
		if (entry_len == name_len
			&& !ft_strncmp(*(char **)ft_vector_get(env, i), name, entry_len))
			return (*(char **)ft_vector_get(env, i) + entry_len + 1);
		i++;
	}
	return (NULL);
}