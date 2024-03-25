/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:41:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/25 18:59:55 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <fcntl.h>

#include "libft.h"
#include "get_next_line.h"

#include "minishelldef.h"
#include "executor.h"

static int	history_print(void);
static int	history_delete(void);
static int	history_usage(void);
static int	history_invalid_option(char *option);

int	builtin_history(t_executor *exec, char **argv)
{
	(void)exec;
	if (!argv[0])
		return (history_print());
	if (argv[0] && argv[1])
		return (history_usage());
	if (argv[0][0] == '-')
	{
		if (argv[0][1] == 'c' && !argv[0][2])
			return (history_delete());
		else
			return (history_invalid_option(argv[0]));
	}
	else
		return (history_usage());
	return (SUCCESS);
}

static int	history_print(void)
{
	int		fd;
	char	*gnl;
	int		i;

	errno = 0;
	fd = open(__GLOBAL_HISTORY, O_RDONLY);
	if (!errno)
	{
		i = 1;
		while (!get_next_line(fd, &gnl) && gnl)
			printf("%5d  %s", i++, gnl);
	}
	return (errno);
}

static int	history_delete(void)
{
	rl_clear_history();
	return (unlink(__GLOBAL_HISTORY));
}

static int	history_usage(void)
{

	ft_dprintf(2, "history: usage: history [-c]\n");
	return (1);
}

static int	history_invalid_option(char *option)
{
	ft_dprintf(2, "%s: history: %s: invalid option\n", __MINISHELL, option);
	return (history_usage() + 1);
}
