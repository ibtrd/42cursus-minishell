/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:34:43 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/07 19:43:49 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	update_var(t_vector *env, char *arg)
{
	char		**var;

	if (!arg)
		return (SUCCESS);
	var = search_var(env, arg, NULL);
	if (!var && add_var(env, arg))
		return (FAILURE);
	if (var && overwrite_var(var, arg))
		return (FAILURE);
	return (SUCCESS);
}
