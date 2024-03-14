/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:34:52 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/14 18:47:56 by ibertran         ###   ########lyon.fr   */
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
int		var_processing(t_env_var *var);
void	free_var(void **var);
int		copy_var(t_env_var *env_var, char *var);
int		add_var(t_vector *envv, char *var);
char	**search_var(t_vector *envv, char *name);
int		del_var(t_vector *envv, char *name);
int		update_var(char **env_var, char *var);

// VAR INIT
int		init_path(t_vector *envv);
int		init_shlvl(t_vector *envv);

#endif