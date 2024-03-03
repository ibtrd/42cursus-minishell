/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:30:10 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/03 02:10:10 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>

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

	do
	{
		input = readline("\nEnter a command line: ");
		if (!input)
			return (0);
		add_history(input);
		if (syntax_checker(input))
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
			status = lexer_analysis(&lexer, 0);
			ft_vector_free(&lexer, NULL);
			free(dup);
			exit(status);
		}
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 0)
				printf("\e[32;1mValid!\e[0m\n");
			else
				printf("\e[31;1mInvalid!\e[0m\n");
		}
		ft_vector_free(&lexer, NULL);
		free(dup);
	} while (1);
}