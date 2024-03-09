/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:31:06 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/09 16:14:21 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>

#include "ast.h"
#include "parsing.h"
#include "env.h"

#include "testing.h" //REMOVE

t_astnode	*ast_test1(void);

int	main(int ac, char **av, char **env)
{
	char		*input;
	t_astnode	*root;
	t_vector	envv;

	(void)ac;
	(void)av;
	// (void)env;
	init_env(&envv, env);
	while (1)
	{
		input = readline("\e[34mminishell$\e[0m ");
		if (!input)
			break ;
		add_history(input);
		root = commandline_parser(input);
		free_ast(root);
	}
	rl_clear_history();
	return (0);
}
