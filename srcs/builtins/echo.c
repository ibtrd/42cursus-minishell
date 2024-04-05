/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:32 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/05 18:02:52 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include "builtins.h"
#include "executor.h"

# include <stdio.h>

int	builtin_echo(t_executor *exec, char **argv)
{
	char	options;

	(void)exec;
	if (!argv)
		return (1);
	options = 0;
	while (*argv && **argv == '-')
	{
		if (check_option((*argv) + 1, &options, "n"))
			break ;
		argv++;
	}
	while (*argv)
	{
		dprintf(2, "argv = %s\n", *argv);
		if (write(1, *argv, ft_strlen(*argv)) == -1)
			return (1);
		if (*(argv + 1))
			if (write(1, " ", 1) == -1)
				return (1);
		argv++;
	}
	if (!(options & 1))
		if (write(1, "\n", 1) == -1)
			return (1);
	return (0);
}
