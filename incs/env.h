/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:34:52 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/14 18:27:49 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "executor.h"
# include "libft.h"

# define __MAX_SHLVL 1000
# define __DEFAULT_PATH "/usr/bin:/bin:/usr/sbin:/sbin"

# define __HIGH_SHLVL "%s: warning: shell level (%d) too high, resetting to 1\n"

typedef struct s_env_var
{
	char	*name;
	char	*value;
}	t_env_var;

char	**search_var(t_vector *envv, char *name, size_t *index);
char	*ft_getenv(t_vector *env, char *name);
int		add_var(t_vector *envv, char *var);
int		copy_var(t_env_var *env_var, char *var);
int		del_var(t_vector *envv, char *name);
int		init_env(t_vector *envv, char **env);
int		overwrite_var(char **env_var, char *var);
int		update_var(t_vector *envv, char *arg);
int		var_processing(t_env_var *var);
void	free_var(void **var);

// VAR INIT
int		init_path(t_vector *envv);
int		init_shlvl(t_vector *envv);

#endif