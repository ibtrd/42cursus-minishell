/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:31:06 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/18 23:03:14 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_ast.h"

#include "testing.h" //REMOVE

t_astnode	*ast_test1(void);

int	main(void)
{
	t_astnode	*root;
	char		*test;

	dup_cmdline("echo -m|rev | int tab&&true", &test);
	printf("TEST dup_cmdline=%s\n", test);
	free(test);
	root = ast_test1();
	print_ast(root);
	free_ast(root);
	return (0);
}
