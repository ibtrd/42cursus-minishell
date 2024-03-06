/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:32 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/06 15:10:54 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	builtin_echo(char **argv)
{
	int	nl;

	if (!argv)
		return (1);
	nl = 1;
	if (ft_strcmp(*argv, "-n") == 0)
	{
		nl = 0;
		argv++;
	}
	while (*argv)
	{
		if (write(1, *argv, ft_strlen(*argv)) == -1)
			return (1);
		if (*(argv + 1))
			if (write(1, " ", 1) == -1)
				return (1);
		argv++;
	}
	if (nl)
		if (write(1, "\n", 1) == -1)
			return (1);
	return (0);
}
