/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:31:06 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/22 18:33:11 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_ast.h"

#include "testing.h" //REMOVE

t_astnode	*ast_test1(void);

int	main(void)
{
	t_astnode	*root;

	root = ast_test1();
	print_ast(root);
	executor_test1(root);
	free_ast(root);
	return (0);
}
