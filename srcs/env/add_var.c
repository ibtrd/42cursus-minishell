/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:01:41 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/15 15:48:18 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "env.h"
#include "libft.h"

int	add_var(t_vector *envv, char *var)
{
	char	*env_var;

	env_var = NULL;
	env_var = ft_strdup(var);
	if (!env_var || ft_vector_insert_ptr(envv, env_var, envv->total - 1))
		return (FAILURE);
	return (SUCCESS);
}
