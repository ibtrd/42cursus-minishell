/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:52:36 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/09 17:54:22 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishelldef.h"
#include "env.h"

int	del_var(t_vector *envv, char *name)
{
	size_t		i;
	t_env_var	*var;

	i = 0;
	while (i < envv->size)
	{
		var = ft_vector_get(envv, i);
		if (!var)
			return (FAILURE);
		if (!ft_strcmp(var->name, name))
		{
			if (ft_vector_delete(envv, i, &free_var))
				return (FAILURE);
			return (SUCCESS);
		}
		i++;
	}
	return (SUCCESS);
}
