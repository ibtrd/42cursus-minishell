/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:31:06 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/17 12:37:02 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>

#include "ast.h"
#include "parsing.h"
#include "executor.h"
#include "env.h"
#include "prompt.h"
#include "minishelldef.h"

#include <stdlib.h>

int	main(int ac, char **av, char **env)
{
	char		*input;
	t_astnode	*root;
	t_vector	envv;
	char		*prompt;

	(void)ac;
	(void)av;
	init_env(&envv, env);
	while (1)
	{
		if (get_prompt(&envv, &prompt))
			input = readline(__DEFAULT_PROMPT);
		else
			input = readline(prompt);
		free(prompt);
		if (!input)
			break ;
		add_history(input);
		root = commandline_parser(input, &envv);
		executor(root, &envv);
		free_ast(root);
	}
	ft_vector_free(&envv);
	rl_clear_history();
	return (0);
}
