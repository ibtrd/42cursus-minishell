/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:22:11 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/06 11:38:22 by ibertran         ###   ########lyon.fr   */
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
		minishell_add_history(*input);
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

int	get_input(t_minishell *minishell, char **input)
{
	char	*prompt;
	int		error;

	if (get_prompt(minishell, &prompt))
		*input = readline(__DEFAULT_PROMPT);
	else
		*input = readline(prompt);
	free(prompt);
	if (!*input)
		return (FAILURE);
	error = SUCCESS;
	signal_setup_input();
	while (check_unclosed_input(*input))
	{
		error = complete_input(input);
		if (error)
			break ;
	}
	signal_setup_main();
	input_error_handler(input, error, &minishell->sp_params.exit_status);
	return (error);
}
