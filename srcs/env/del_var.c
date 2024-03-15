/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:52:36 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/15 15:47:49 by kchillon         ###   ########lyon.fr   */
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
	char		**var;

	if (!envv || !name)
		return (FAILURE);
	name_len = ft_strlen(name);
	i = 0;
	var = (char **)ft_vector_get(envv, i);
	while (var && *var)
	{
		entry_len = ft_strlen_charset(*var, "=");
		if (entry_len == name_len
			&& !ft_strncmp(*var, name, entry_len))
			return (ft_vector_delete(envv, i));
		i++;
		var = (char **)ft_vector_get(envv, i);
	}
	return (SUCCESS);
}
