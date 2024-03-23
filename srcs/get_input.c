/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:22:11 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/23 18:55:27 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishelldef.h"
#include "prompt.h"
#include "parsing.h"

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

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
	if (check_unclosed_input(*input))
		if (get_additional_input(minishell, input))
			return (1);
	// while (check_unclosed_input(*input))
	// 	if (complete_input(input))
	// 		return (FAILURE);
	add_history(*input);
	return (0);
}

// static int	complete_input(char **old_input)
// {
// 	char	*new_input;
// 	char	*joined_inputs;
// 	char	*prompt;

// 	prompt = ft_sprintf(" %s%s%s ", P_YELLOW, __SECONDARY_PROMPT, P_RESET);
// 	if (!prompt)
// 		return (FAILURE);
// 	new_input = readline(prompt);
// 	free(prompt);
// 	if (!new_input)
// 		return (FAILURE);
// 	joined_inputs = ft_strjoin2(*old_input, "\n", new_input);
// 	free(*old_input);
// 	free(new_input);
// 	*old_input = joined_inputs;
// 	if (!joined_inputs)
// 		return (FAILURE);
// 	return (SUCCESS);
// }
