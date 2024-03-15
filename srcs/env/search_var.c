/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:10:26 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/15 15:47:57 by kchillon         ###   ########lyon.fr   */
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
	char		**var;

	name_len = ft_strlen_charset(name, "=");
	i = 0;
	var = (char **)ft_vector_get(envv, i);
	while (var && *var)
	{
		entry_len = ft_strlen_charset(*var, "=");
		if (entry_len == name_len
			&& !ft_strncmp(*var, name, entry_len))
			return (var);
		i++;
		var = (char **)ft_vector_get(envv, i);
	}
	return (NULL);
}
