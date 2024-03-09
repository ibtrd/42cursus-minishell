/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:10:26 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/09 19:30:08 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "env.h"
#include "libft.h"

#include <stdlib.h>

t_env_var	*search_var(t_vector *envv, char *name)
{
	size_t		i;
	size_t		len;
	t_env_var	*var;
	char		*tmp;

	len = 0;
	while (name[len] && name[len] != '=')
		len++;
	tmp = ft_strndup(name, len);
	i = 0;
	while (i < envv->total)
	{
		var = ft_vector_get(envv, i);
		if (!var)
			return (NULL);
		if (!ft_strcmp(var->name, tmp))
		{
			free(tmp);
			return (var);
		}
		i++;
	}
	free(tmp);
	return (NULL);
}
