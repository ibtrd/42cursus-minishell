/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:30:10 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/18 04:44:01 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "minishelldef.h"
#include "ast.h"
#include "parsing.h"
#include "lexer.h"

int	main(void)
{
	t_vector			lexer;
	char				*input;
	char 				*dup = NULL;
	__pid_t				pid;
	int					status;
	int					outfile;

	outfile = open("./TEST_DIR/lexer_out", O_WRONLY |O_TRUNC | O_CREAT, 0777);
	do
	{;
		input = readline("\n> ");
		if (!input)
			return (0);
		add_history(input);
		if (check_unclosed_input(input))
		{
			free(input);
			continue ;
		}
		cmdline_addspace(input, &dup);
		free(input);
		lexer_build(dup, &lexer);

		pid = fork();
		if (!pid)
		{
			close(1);
			status = lexer_launch(&lexer, 0);
			ft_vector_free(&lexer, NULL);
			free(dup);
			exit(status);
		}
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 0)
			{
				write(outfile, "OK!\n", 4);
				printf("\e[32;1mValid!\e[0m\n");
				rl_on_new_line();
			}
			else
			{
				write(outfile, "KO!\n", 4);
				printf("\e[31;1mInvalid!\e[0m\n");
				rl_on_new_line();
			}
		}
		ft_vector_free(&lexer, NULL);
		free(dup);
	} while (1);
}