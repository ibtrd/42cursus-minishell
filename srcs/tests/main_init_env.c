/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:41:08 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/08 15:22:40 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "builtins.h"
#include "libft.h"

#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	t_vector	envv;
	// size_t		i;

	(void)ac;
	(void)av;
	(void)env;
	(void)envv;

	envv = (t_vector){0};
	init_env(&envv, env);
	builtin_env(&envv);
	printf("\n");
	printf("ft_getenv(envv, \"PATH\") = %s\n", ft_getenv(&envv, "PATH"));
	ft_vector_free(&envv, &free_var);
	return (0);
}
