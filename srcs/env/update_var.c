/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:00:47 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/09 19:30:17 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

#include <stdlib.h>

int	update_var(t_env_var *env_var, char *var)
{
	char	*new_value;

	free(env_var->value);
	new_value = ft_strchr(var, '=');
	if (!new_value)
		env_var->value = ft_strdup(var);
	else
		env_var->value = ft_strdup(++new_value);
	return (!env_var->value);
}
