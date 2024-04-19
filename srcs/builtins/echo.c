/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:32 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/19 14:50:44 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "builtins.h"
#include "libft.h"

int	builtin_echo(t_executor *exec, char **argv)
{
	char	options;

	(void)exec;
	if (!argv)
		return (1);
	options = 0;
	while (*argv && **argv == '-' && *(*argv + 1))
	{
		if (check_option((*argv) + 1, &options, "n"))
			break ;
		argv++;
	}
	while (*argv)
	{
		if (write(STDOUT_FILENO, *argv, ft_strlen(*argv)) == -1)
			return (1);
		if (*(argv + 1))
			if (write(1, " ", 1) == -1)
				return (1);
		argv++;
	}
	if (!(options & 1))
		if (write(STDOUT_FILENO, "\n", 1) == -1)
			return (1);
	return (0);
}
