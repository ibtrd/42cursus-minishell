/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:32:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/06 15:11:16 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "minishelldef.h"
#include "builtins.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	char	**args = malloc(sizeof(char *) * 4);
	args[0] = "";
	args[1] = "oui";
	args[2] = "non";
	args[3] = NULL;
	builtin_echo(args);
	free(args);
	return (0);
}
