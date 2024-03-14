/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:10:26 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/12 17:53:05 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "env.h"
#include "libft.h"

#include <stdlib.h>

char	**search_var(t_vector *envv, char *name)
{
	size_t		i;
	size_t		name_len;
	size_t		entry_len;

	name_len = ft_strlen_charset(name, "=");
	i = 0;
	while (i < envv->total)
	{
		entry_len = ft_strlen_charset(*(char **)ft_vector_get(envv, i), "=");
		if (entry_len == name_len
			&& !ft_strncmp(*(char **)ft_vector_get(envv, i), name, entry_len))
			return ((char **)ft_vector_get(envv, i));
		i++;
	}
	return (NULL);
}
