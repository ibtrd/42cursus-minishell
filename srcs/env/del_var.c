/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:52:36 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/12 18:32:16 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishelldef.h"
#include "env.h"

int	del_var(t_vector *envv, char *name)
{
	size_t		i;
	size_t		entry_len;
	size_t		name_len;

	if (!envv || !name)
		return (FAILURE);
	name_len = ft_strlen(name);
	i = 0;
	while (i < envv->total)
	{
		entry_len = ft_strlen_charset(*(char **)ft_vector_get(envv, i), "=");
		if (entry_len == name_len
			&& !ft_strncmp(*(char **)ft_vector_get(envv, i), name, entry_len))
			return (ft_vector_delete(envv, i));
		i++;
	}
	return (SUCCESS);
}

// int	del_var(t_vector *envv, char *name)
// {
// 	size_t		i;
// 	t_env_var	*var;

// 	i = 0;
// 	while (i < envv->size)
// 	{
// 		var = ft_vector_get(envv, i);
// 		if (!var)
// 			return (FAILURE);
// 		if (!ft_strcmp(var->name, name))
// 		{
// 			if (ft_vector_delete(envv, i))
// 				return (FAILURE);
// 			return (SUCCESS);
// 		}
// 		i++;
// 	}
// 	return (SUCCESS);
// }
