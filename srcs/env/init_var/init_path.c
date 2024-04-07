/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:58:16 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/07 19:41:28 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

#include <stdlib.h>

int	init_path(t_vector *env)
{
	char		*var;
	int			error;	

	if (ft_getenv(env, "PATH"))
		return (SUCCESS);
	var = ft_strjoin("PATH=", __DEFAULT_PATH);
	error = !var || update_var(env, var);
	free(var);
	return (error);
}
