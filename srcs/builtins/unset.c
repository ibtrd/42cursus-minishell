/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:20:47 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/06 16:52:26 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	builtin_unset(t_executor *exec, char **argv)
{
	size_t		i;

	if (!argv)
		return (FAILURE);
	i = -1;
	while (argv[++i])
	{
		if (del_var(exec->env, argv[i]))
			return (FAILURE);
	}
	return (SUCCESS);
}
