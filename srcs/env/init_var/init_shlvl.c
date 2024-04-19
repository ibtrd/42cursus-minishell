/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shlvl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:17:51 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/19 23:30:32 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "env.h"
#include "minishelldef.h"

static int	get_shlvl(t_vector *env)
{
	int		shlvl_int;
	char	*shlvl;

	shlvl = ft_getenv(env, "SHLVL");
	if (!shlvl)
		return (0);
	shlvl_int = ft_atoi(shlvl);
	if (shlvl_int <= 0)
		return (0);
	if (shlvl_int + 1 >= __MAX_SHLVL)
	{
		ft_dprintf(STDERR_FILENO, __HIGH_SHLVL, __MINISHELL, shlvl_int + 1);
		return (0);
	}
	return (shlvl_int);
}

int	init_shlvl(t_vector *env)
{
	char		*var;
	char		*shlvl;
	int			shlvl_int;
	int			error;	

	shlvl_int = 1;
	shlvl_int += get_shlvl(env);
	shlvl = ft_itoa(shlvl_int);
	if (!shlvl)
		return (FAILURE);
	var = ft_strjoin("SHLVL=", shlvl);
	free(shlvl);
	error = !var || update_var(env, var);
	free(var);
	return (error);
}
