/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:21:50 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/15 15:47:40 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*ft_getenv(t_vector *env, char *name)
{
	size_t		i;
	size_t		entry_len;
	size_t		name_len;
	char		**var;

	if (!env || !name)
		return (NULL);
	name_len = ft_strlen(name);
	i = 0;
	var = (char **)ft_vector_get(env, i);
	while (var && *var)
	{
		entry_len = ft_strlen_charset(*var, "=");
		if (entry_len == name_len
			&& !ft_strncmp(*var, name, entry_len))
			return (*var + entry_len + 1);
		i++;
		var = (char **)ft_vector_get(env, i);
	}
	return (NULL);
}
