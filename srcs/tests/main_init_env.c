/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:41:08 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/06 16:02:43 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	t_vector	envv;
	size_t		i;

	(void)ac;
	(void)av;
	(void)env;
	(void)envv;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		// printf("env[%zu] = %s\n", i, env[i]);
		i++;
	}

	// printf("\nenvv.size = %zu\n\n\n", envv.size);
	// init_env(&envv, env);
	return (0);
}