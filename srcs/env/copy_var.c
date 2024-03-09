/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:24:52 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/09 18:09:01 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

#include <stdlib.h>

int	copy_var(t_env_var *env_var, char *var)
{
	char	*tmp;

	tmp = ft_strtok(var, "=");
	env_var->name = ft_strdup(tmp);
	if (!env_var->name)
		return (1);
	tmp = ft_strtok(NULL, "");
	if (!tmp)
		env_var->value = ft_strdup("");
	else
		env_var->value = ft_strdup(tmp);
	if (!env_var->value)
	{
		free(env_var->name);
		return (1);
	}
	return (0);
}
