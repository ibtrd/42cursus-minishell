/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_test1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:31:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/20 00:24:57 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "minishell_ast.h"
#include "libft.h"

t_astnode	*ast_test1(void)
{
	t_astnode	*a;
	t_astnode	*b;
	t_astnode	*c;
	t_astnode	*d;
	t_astnode	*e;

	ast_newnode(&a, _AND, NULL);
	ast_newnode(&b, _CMD, ft_split("make -C ../push_swap", ' '));
	ast_newnode(&c, _PIPE, NULL);
	ast_newnode(&d, _CMD, ft_split("../push_swap/push_swap 1 3 2", ' '));
	ast_newnode(&e, _CMD, ft_split("../push_swap/checker 1 3 2", ' '));
	a->left = b;
	a->right = c;
	c->left = d;
	c->right = e;
	return (a);
}
