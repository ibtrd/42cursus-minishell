/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:34:43 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/21 13:21:43 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "env.h"
#include "libft.h"
#include "executor.h"

#include <unistd.h>

int	update_var(t_vector *env, char *arg)
{
	char		**var;

	var = search_var(env, arg, NULL);
	if (!var && add_var(env, arg))
		return (FAILURE);
	if (var && overwrite_var(var, arg))
		return (FAILURE);
	return (SUCCESS);
}
