/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:27:27 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/07 19:42:20 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

#include <stdlib.h>

void	free_var(void **var)
{
	t_env_var	*env_var;

	env_var = (t_env_var *)var;
	free(env_var->name);
	env_var->name = NULL;
	free(env_var->value);
	env_var->value = NULL;
}
