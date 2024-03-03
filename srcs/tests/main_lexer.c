/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:30:10 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/03 01:14:08 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "minishelldef.h"
#include "ast.h"
#include "parsing.h"
#include "lexer.h"

int	main(void)
{
	t_vector			lexer;
	char				*input;
	char 				*dup = NULL;

	do
	{
		input = readline("\nEnter a command line: ");
		if (!input)
			return (0);
		if (syntax_checker(input))
		{
			free(input);
			continue ;
		}
		cmdline_addspace(input, &dup);
		free(input);
		lexer_build(dup, &lexer);

		if (!lexer_analysis(&lexer, 0))
			printf("\e[32;1mValid!\e[0m\n\n");
		else
			printf("\e[31;1mInvalid!\e[0m\n\n");
		
		printf("\n");
		ft_vector_free(&lexer, NULL);
		free(dup);
	} while (1);
}