/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:44:37 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/20 13:20:27 by ibertran         ###   ########lyon.fr   */
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
	return (0);
}

void	test_dup_cmdline(char *str)
{
	char	*ptr;

	printf("cmdline| \e[33m%s\e[0m\n", str);
	dup_cmdline(str, &ptr);
	printf("    dup| \e[34m%s\e[0m\n\n", ptr);
	free(ptr);
}
