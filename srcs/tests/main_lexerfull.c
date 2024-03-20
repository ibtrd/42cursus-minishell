/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lexerfull.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:30:10 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/18 04:44:01 by ibertran         ###   ########lyon.fr   */
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
	size_t 				i;
	t_lexer_token 		*lextok;

	static const char	*operator[] = {
			"\e[46mAND\e[0m   ",
			"\e[46mOR\e[0m   ",
			"\e[44mPIPE\e[0m   ",
			"\e[33mINPUT\e[0m   ",
			"\e[32mOUTPUT\e[0m   ",
			"\e[43mHEREDOC\e[0m   ",
			"\e[42mAPPEND\e[0m   ",
			"\e[31mPRIO_OPEN\e[0m   ",
			"\e[31mPRIO_CLOSE\e[0m   ",
			"\e[00mCMD\e[0m   ",
			"\e[00mARG\e[0m   ",
			"\e[00mFILE\e[0m   ",
			"\e[41mINVALID\e[0m   ",
			"\e[41mEND\e[0m   ",
		};

	do
	{
		input = readline("\nEnter a command line: ");
		add_history(input);
		
		printf("\ninput            | \e[33m%s\e[0m\n", input);

		printf("\n\n\e[37;40mUNCLOSED_CHECK  ");
		if (!check_unclosed_input(input))
			printf("\e[32;1mValid!\e[0m\n\n");
		else
		{
			printf("\e[31;1mInvalid!\e[0m\n\n");
			printf("\n");
			free(input);
			continue ;
		}

		cmdline_addspace(input, &dup);
		printf("cmdline_addspace | \e[34m%s\e[0m\n\n", dup);
		
		free(input);
		lexer_build(dup, &lexer);

		i = 0;
		while (i < lexer.total)
		{
			lextok = ft_vector_get(&lexer, i);
			printf("token-%-3zu %25s %s\n", i , operator[lextok->type], lextok->value);
			i++;
		}

		printf("\n\n\e[37;40mlexer_launch  ");
		if (!lexer_launch(&lexer, 0))
			printf("\e[32;1mValid!\e[0m\n\n");
		else
			printf("\e[31;1mInvalid!\e[0m\n\n");
		
		lexer_set_args(&lexer);
		i = 0;
		while (i < lexer.total)
		{
			lextok = ft_vector_get(&lexer, i);
			printf("token-%-3zu %25s %s\n", i , operator[lextok->type], lextok->value);
			i++;
		}
		printf("\n");
		ft_vector_free(&lexer, NULL);
		free(dup);
	} while (1);
}