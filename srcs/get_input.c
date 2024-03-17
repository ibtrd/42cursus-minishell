/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:22:11 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/17 17:29:34 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishelldef.h"
#include "prompt.h"

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int	get_input(t_minishell *minishell, char **input)
{
	char		*prompt;
	if (get_prompt(&minishell->env, &prompt))
		*input = readline(__DEFAULT_PROMPT);
	else
		*input = readline(prompt);
	free(prompt);
	if (!*input)
		return (1) ;
	add_history(*input);
	return (0);
}
