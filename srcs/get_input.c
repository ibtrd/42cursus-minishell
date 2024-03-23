/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:22:11 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/23 17:43:27 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishelldef.h"
#include "prompt.h"
#include "parsing.h"

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

static int	complete_input(char **old_input);

int	get_input(t_minishell *minishell, char **input)
{
	char	*prompt;

	if (get_prompt(minishell, &prompt))
		*input = readline(__DEFAULT_PROMPT);
	else
		*input = readline(prompt);
	free(prompt);
	if (!*input)
		return (1);
	while (check_unclosed_input(*input))
		if (complete_input(input))
			return (FAILURE);
	minishell_add_history(*input);
	return (0);
}

static int	complete_input(char **old_input)
{
	char	*new_input;
	char	*joined_inputs;
	char	*prompt;

	prompt = ft_sprintf(" %s%s%s ", P_YELLOW, __SECONDARY_PROMPT, P_RESET);
	if (!prompt)
		return (FAILURE);
	new_input = readline(prompt);
	free(prompt);
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

