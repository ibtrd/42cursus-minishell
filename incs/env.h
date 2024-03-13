/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:34:52 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/11 00:20:53 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

#include "libft.h"

typedef struct s_env_var
{
	char	*name;
	char	*value;
}	t_env_var;

char	*ft_getenv(t_vector *env, char *name);
int		init_env(t_vector *envv, char **env);
int		var_update(t_env_var *var);
void	free_var(void **var);

// VAR INIT
int		init_path(t_vector *envv);
int		init_shlvl(t_vector *envv);

#endif