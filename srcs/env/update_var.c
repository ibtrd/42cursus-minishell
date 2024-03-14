/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:00:47 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/12 17:51:10 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

#include <stdlib.h>

int	update_var(char **env_var, char *var)
{
	free(*env_var);
	*env_var = ft_strdup(var);
	return (!*env_var);
}
