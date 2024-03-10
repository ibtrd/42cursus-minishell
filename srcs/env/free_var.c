/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:27:27 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/10 19:47:45 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdlib.h>

#include <stdio.h>

void	free_var(void **var)
{
	t_env_var	*env_var;

	env_var = (t_env_var *)var;
	free(env_var->name);
	free(env_var->value);
}
