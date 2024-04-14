/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:42:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/14 14:16:55 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>

#include "history.h"
#include "minishelldef.h"
#include "parsing.h"
#include "prompt.h"
#include "signals.h"

static int	complete_input(char **old_input)
{
	char	*new_input;
	char	*joined_inputs;

	g_signal = 0;
	new_input = readline(__SECONDARY_PROMPT);
	if (g_signal)
	{
		free(new_input);
		return (g_signal << 4);
	}
	if (!new_input)
		return (2);
	joined_inputs = ft_strjoin2(*old_input, "\n", new_input);
	free(*old_input);
	free(new_input);
	*old_input = joined_inputs;
	if (!joined_inputs)
		return (FAILURE);
	return (SUCCESS);
}

static void	input_error_handler(char **input, int error, int *exit_status)
{
	int	quote;

	if (error != FAILURE && *input && **input)
		add_minishell_history(*input);
	if (error == 2)
	{
		quote = check_quotes(*input);
		if (quote)
			ft_dprintf(STDERR_FILENO, __UNEXPECTED_EOF, __MINISHELL, quote);
		*exit_status = 2;
		free(*input);
		*input = NULL;
	}
	else if (error)
	{
		*exit_status = (error >> 4) + 128;
		free(*input);
		*input = NULL;
	}
}

static int	get_input(t_minishell *minishell, char **input, void *color_flag)
{
	char	*prompt;
	int		error;

	g_signal = 0;
	if (get_prompt(minishell, &prompt, color_flag))
		*input = readline(__DEFAULT_PROMPT);
	else
		*input = readline(prompt);
	free(prompt);
	if (!*input)
		return (EOF);
	error = SUCCESS;
	if (g_signal)
	{
		free(*input);
		return (error);
	}
	while (check_unclosed_input(*input))
	{
		error = complete_input(input);
		if (error)
			break ;
	}
	input_error_handler(input, error, &minishell->sp_params.exit_status);
	return (error);
}

int	interpreter_routine(t_minishell *minishell, void *color_flag)
{
	char		*input;
	t_astnode	*root;
	int			error;

	error = get_input(minishell, &input, color_flag);
	if (error)
		return (error == EOF);
	if (g_signal)
	{
		minishell->sp_params.exit_status = g_signal + 128;
		return (0);
	}
	root = commandline_parser(input, &minishell->sp_params.exit_status);
	if (!root)
		return (0);
	if (create_here_documents(root))
	{
		free_ast(root);
		if (g_signal)
			minishell->sp_params.exit_status = g_signal + 128;
		else
			minishell->sp_params.exit_status = 1;
		return (0);
	}
	return (executor(root, minishell));
}
