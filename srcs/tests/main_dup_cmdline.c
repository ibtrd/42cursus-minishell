/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dup_cmdline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:44:37 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/22 13:22:19 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "minishell_def.h"
#include "minishell_ast.h"
#include "minishell_parsing.h"

void	test_dup_cmdline(char *str);

int	main(void)
{
	printf("TESTING DUP_CMDLINE\n\n");
	test_dup_cmdline("Echo -n");
	test_dup_cmdline("Make && ./push_swap 5 4 8 7 | ./checker 5 4 8 7");
	test_dup_cmdline("Make&&./push_swap 5 4 8 7|./checker 5 4 8 7");
	test_dup_cmdline("Make&&&&./push_swap 5 4 8 7|./checker 5 4 8 7");
	test_dup_cmdline("Make&&./push_swap \"5 4 8 7\"|./checker 5 4 8 7");
	test_dup_cmdline("<input cat|head>output");
	test_dup_cmdline("<<EOF cat|head>>output");
	test_dup_cmdline("<<'EOF|' cat|head>>output");
	test_dup_cmdline("<<'EOF|' cat|head>>output |\"\"");
	test_dup_cmdline("<<\"EOF|\" cat|head>>output |\"\"");
	test_dup_cmdline("<<'\"EOF|\"' cat|head>>output |\"\"");
	test_dup_cmdline("<<'EOF|' cat|head>>output |\"\"");
	test_dup_cmdline("Make && (./push_swap 5 4 8 7 | ./checker 5 4 8 7 || true)");
	test_dup_cmdline("<><>cat || &|head | ||| ls \"|>\" ");
	test_dup_cmdline("e'ch'o \"'$VAR'$VAR\" && < input1 >> out1 cat << EOF > out2 && (< Makefile cat -e | head -n 5 || << EOF tail) | rev > out3 >> out2  >> out1 ||./push_swap $ARG|./checker $ARG");
	test_dup_cmdline("ls && (((>((true||true))) && ls");
	test_dup_cmdline("ls      \"\"         &&                ls");
	return (0);
}

void	test_dup_cmdline(char *str)
{
	char	*ptr;
	char	*token;

	printf("cmdline| \e[33m%s\e[0m\n", str);
	dup_cmdline(str, &ptr);
	printf("    dup| \e[34m%s\e[0m\n\n", ptr);
	token = tokenizer(ptr);
	while (token)
	{
		printf ("token| %s\n", token);
		token = tokenizer(NULL);
	}
	printf("\n\n");
	free(ptr);
}
