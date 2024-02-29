/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:30:10 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/29 18:46:28 by ibertran         ###   ########lyon.fr   */
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
	char		*input;
	t_vector	lexer;

	input = readline("\nEnter a command line: ");

	char *dup;
	cmdline_addspace(input, &dup);
	
	size_t i = 0;
	printf("\ninput            | \e[33m%s\e[0m\n\n", input);
	printf("cmdline_addspace | \e[34m%s\e[0m\n\n", dup);
	free(input);
	build_lexer(dup, &lexer);
	
	t_lexer_token *lextok;

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
		"\e[41mINVALID\e[0m   "
	};

	while (i < lexer.total)
	{
		lextok = ft_vector_get(&lexer, i);
		printf("token-%-3zu %25s %s\n", i , operator[lextok->type], lextok->value);
		i++;
	}
	ft_vector_free(&lexer);
	free(dup);
}