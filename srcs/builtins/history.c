/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:41:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/03 15:08:34 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

#include "libft.h"
#include "get_next_line.h"

#include "minishelldef.h"
#include "executor.h"
#include "builtins.h"
#include "history.h"

static int	history_print(void);
static int	history_delete(void);
static int	history_usage(void);
static int	history_invalid_option(char *option);

int	builtin_history(t_executor *exec, char **argv)
{
	char	options;

	(void)exec;
	if (!argv)
		return (1);
	options = 0;
	while (*argv)
	{
		if (**argv == '-' && check_option((*argv) + 1, &options, "c"))
			return (history_usage() + history_invalid_option(*argv));
		if (**argv != '-' && !options)
			return (history_usage());
		argv++;
	}
	if (options & 1)
		return (history_delete());
	return (history_print());
}

static int	history_print(void)
{
	char	*history_file;
	int		fd;
	char	*gnl;
	int		i;

	history_file = get_history_filepath();
	if (!history_file)
		return (1);
	errno = 0;
	fd = open(history_file, O_RDONLY);
	free(history_file);
	if (!errno)
	{
		i = 1;
		while (!get_next_line(fd, &gnl) && gnl)
			printf("%5d  %s", i++, gnl);
	}
	close(fd);
	return (errno);
}

static int	history_delete(void)
{
	char	*history_file;
	int		status;

	rl_clear_history();
	history_file = get_history_filepath();
	if (!history_file)
		return (1);
	status = unlink(history_file);
	free(history_file);
	return(status);
}

static int	history_usage(void)
{
	ft_dprintf(2, "history: usage: history [-c]\n");
	return (1);
}

static int	history_invalid_option(char *option)
{
	ft_dprintf(2, "%s: history: %s: invalid option\n", __MINISHELL, option);
	return (1);
}
