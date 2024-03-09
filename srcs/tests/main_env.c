/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:41:08 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/09 19:36:18 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "builtins.h"
#include "libft.h"

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av, char **env)
{
	t_vector	envv;
	int		ret;
	char	*envp[8];

	(void)ac;
	(void)av;
	(void)env;
	(void)envv;

	envp[0] = ft_strdup("1TRUC=truc");
	envp[1] = ft_strdup("_EMPTY");
	envp[2] = ft_strdup("OUI=0");
	envp[3] = ft_strdup("OU-I=0");
	envp[4] = ft_strdup("TRUC=truc");
	envp[5] = ft_strdup("OUI=1");
	envp[6] = ft_strdup("EMPTY=");
	envp[7] = NULL;
	// printf("env: %p\n", env);
	envv = (t_vector){0};
	init_env(&envv, env);
	dprintf(2, "ORIGINAL env:\n\n");
	builtin_env(&envv);
	dprintf(2, "\n\n");
	printf("ft_getenv(envv, \"PATH\") = %s\n", ft_getenv(&envv, "PATH"));
	dprintf(2, "\n\n");
	dprintf(2, "export:\n\n");
	ret = builtin_export(&envv, envp);
	dprintf(2, "ret = %d\n", ret);
	dprintf(2, "\n\n");
	dprintf(2, "EXPORT env:\n\n");
	builtin_env(&envv);
	ft_vector_free(&envv, &free_var);
	dprintf(2, "\n\n");
	free(envp[0]);
	free(envp[1]);
	free(envp[2]);
	free(envp[3]);
	free(envp[4]);
	free(envp[5]);
	free(envp[6]);
	return (0);
}
