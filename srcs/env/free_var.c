/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:27:27 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/09 18:54:07 by kchillon         ###   ########lyon.fr   */
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
	env_var->name = NULL;
	free(env_var->value);
	env_var->value = NULL;
}
