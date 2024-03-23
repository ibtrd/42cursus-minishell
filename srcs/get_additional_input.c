/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_additional_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:47:49 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/23 19:46:41 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "minishell.h"
#include "executor.h"
#include "libft.h"
#include "parsing.h"

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

# include <stdio.h>

static int    additional_input_fork(t_minishell *minishell, char **input, int pipefd[2])
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == -1)
		return (FAILURE);
	if (pid == 0)
	{
		close(pipefd[0]);
		ret = 0;
		while (check_unclosed_input(*input) && !ret)
			ret = complete_input(input);
		if (!ret)
			ret = write(pipefd[1], *input, ft_strlen(*input));
		dprintf(2, "len = %zu\tinput: |%s|\n", ft_strlen(*input), *input);
		free(*input);
		close(pipefd[1]);
		ft_vector_free(&minishell->env);
		exit(ret == -1);
	}
	close(pipefd[1]);
	return (retrieve_status(pid));
}

// static int	catch_additional_input(int read_fd, char **old_input)
// {
// 	int		ret;
// 	char	*new_input;
// 	char	*joined_inputs;

// 	ret = get_next_line(read_fd, &new_input);
// 		joined_inputs = ft_strjoin2(*old_input, "\n", new_input);
// 		free(*old_input);
// 		free(new_input);
// 		*old_input = joined_inputs;
// 	close(read_fd);
// 	if (ret)
// 		free(*old_input);
// 	return (ret);
// }

int    get_additional_input(t_minishell *minishell, char **old_input)
{
	int		pipefd[2];
	int		ret;

	if (pipe(pipefd) == -1)
		return (1);
	ret = additional_input_fork(minishell, old_input, pipefd);
	dprintf(2, "fork ret: %d\n", ret);
	if (ret)
	{
		close(pipefd[0]);
		minishell->sp_params.exit_status = ret;
		return (FAILURE);
	}
	free(*old_input);
	ret = get_fd_content(pipefd[0], old_input);
	dprintf(2, "old_input: |%s|\n", *old_input);
	close(pipefd[0]);
	return (ret);
}
