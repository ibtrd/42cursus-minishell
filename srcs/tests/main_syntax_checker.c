/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_syntax_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:32:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/29 01:50:08 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "minishelldef.h"
#include "ast.h"
#include "parsing.h"

void	test_syntax_checker(char *str, bool expected);

int	main(void)
{
	printf("TESTING SYNTAX_CHECKER\n\n");
	test_syntax_checker("Echo -n", 1);
	test_syntax_checker("make && 'make run'", 1);
	test_syntax_checker("make && ''make run'", 0);
	test_syntax_checker("mak\"e && 'make run", 0);
	test_syntax_checker("mak'e && \"make run", 0);
	test_syntax_checker("m\"ak'\"e' ./minishell", 0);
	test_syntax_checker("m\"ak'\"e\" && ./minishell", 0);
	test_syntax_checker("m'ak\"e' && ./minishell", 1);
	test_syntax_checker("\"dewiu '' fedw '' '''''''\"", 1);
	test_syntax_checker("make \" ' \"", 1);
	test_syntax_checker("\"'$ARG'\"", 1);
	test_syntax_checker("'\"$ARG\"'", 1);

	test_syntax_checker("(false || true) || (true || true)", 1);
	test_syntax_checker("(false |(| true) || (true || true)", 0);
	test_syntax_checker("(false || 'true)' || (true || true)", 0);
	test_syntax_checker("(false || '(true)') || (true || true)", 1);
	test_syntax_checker("(false || '(true)') || (\")\"true || true)", 1);
	test_syntax_checker("(false || '(true)') || (\")\"true || true))", 0);

	test_syntax_checker("(<< . cat | head | tail && << * (tac || rev) > test) > test2", 0);
}

void	test_syntax_checker(char *str, bool expected)
{
	int		i;

	printf("cmdline | \e[33m%s\e[0m\n", str);
	if (expected)
		printf("expected| \e[34m%s\e[0m\n", "valid");
	else
		printf("expected| \e[31m%s\e[0m\n", "invalid");
	i = syntax_checker(str);
	if (!i)
		printf("  result| \e[44m%s\e[0m\n\n", "valid");
	else
		printf("  result| \e[41m%s\e[0m\n\n", "invalid");
}
