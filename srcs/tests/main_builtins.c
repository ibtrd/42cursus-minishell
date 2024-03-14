/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:32:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/14 15:17:35 by kchillon         ###   ########lyon.fr   */
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
	char	**args = malloc(sizeof(char *) * 10);
	args[0] = "-nnnnn";
	args[1] = "-n";
	args[2] = "-nan";
	args[3] = "oui";
	args[4] = "";
	args[5] = "non";
	args[6] = " ";
	args[7] = "-n";
	args[8] = "a";
	args[9] = NULL;
	builtin_echo(args);
	free(args);
	return (0);
}
