/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_additional_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:47:49 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/23 22:05:30 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "minishell.h"
#include "executor.h"
#include "libft.h"
#include "parsing.h"
#include "signals.h"

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <readline/readline.h>
// #include <errno.h>
// #include <string.h>
// #include <sys/stat.h>

static int	complete_input(char **old_input)
{
	char	*new_input;
	char	*joined_inputs;

	new_input = readline(__SECONDARY_PROMPT);
	if (!new_input)
		return (FAILURE);
	joined_inputs = ft_strjoin2(*old_input, "\n", new_input);
	free(*old_input);
	free(new_input);
	*old_input = joined_inputs;
	if (!joined_inputs)
		return (FAILURE);
	return (SUCCESS);
}

static int    additional_input_fork(t_minishell *minishell, char **input, int pipefd[2])
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == -1)
		return (FAILURE);
	if (pid == 0)
	{
		ret = signal_setup_input();
		close(pipefd[0]);
		while (!ret && check_unclosed_input(*input))
			ret = complete_input(input);
		if (!ret)
			ret = write(pipefd[1], *input, ft_strlen(*input)) < 0;
		free(*input);
		close(pipefd[1]);
		ft_vector_free(&minishell->env);
		exit(ret);
	}
	close(pipefd[1]);
	return (retrieve_status(pid));
}

int    get_additional_input(t_minishell *minishell, char **old_input)
{
	int		pipefd[2];
	int		ret;

	if (pipe(pipefd) == -1)
		return (1);
	if (signal_ign_main())
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (1);
	}
	ret = additional_input_fork(minishell, old_input, pipefd);
	if (signal_setup_main() && ret)
	{
		close(pipefd[0]);
		minishell->sp_params.exit_status = ret;
		return (FAILURE);
	}
	free(*old_input);
	ret = get_fd_content(pipefd[0], old_input);
	close(pipefd[0]);
	minishell->sp_params.exit_status = ret;
	return (ret);
}
