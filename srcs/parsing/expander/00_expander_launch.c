/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_expander_launch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:20:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/13 10:09:30 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "ast.h"
#include "env.h"
#include "expander.h"
#include "interpreter.h"

static int	expand_node(t_astnode *node, t_vector *env);
static int	expand_string(t_vector *args, size_t *index, t_vector *env);

int	expander_launch(t_astnode *node, t_vector *env)
{
	if (!node)
		return (SUCCESS);
	if (expand_node(node, env))
		return (FAILURE);
	if (expander_launch(node->left, env) || expander_launch(node->right, env))
		return (FAILURE);
	return (SUCCESS);
}

static int	expand_node(t_astnode *node, t_vector *env)
{
	t_vector	*arg;
	size_t		i;

	if (node->type != _CMD && (node->type < _INPUT || node->type > _APPEND))
		return (SUCCESS);
	i = 0;
	while (i < node->args->total)
	{
		arg = (ft_vector_get(node->args, i));
		if (is_expandable(arg) && expand_string(node->args, &i, env))
			return (FAILURE);
		i++;
	}
	return (args_vectors_to_stings(&node->args, node->type));
}

static int	expand_string(t_vector *args, size_t *index, t_vector *env)
{
	t_vector	*str;

	str = ft_vector_get(args, *index);
	if (tilde_expansion(str))
		return (FAILURE);

	printf("TILDE EXPAND\n"); //DEBUG
	ft_vector_print(args, ft_vprint_char, "arg:"); //DEBUG
	ft_vector_print(args, debug_print_mask, "mask"); //DEBUG

	// if (envars_expansion(str, masks, *index, env))
	// 	return (FAILURE);
	// if (word_splitting(str, masks, index))
	// 	return (FAILURE);
	// if (quote_removal(str, masks, index))
	// 	return (FAILURE);
	return (SUCCESS);
	(void)env;
}
