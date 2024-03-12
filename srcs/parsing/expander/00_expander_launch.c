/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_expander_launch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:20:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 04:50:51 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "ast.h"
#include "env.h"
#include "expander.h"
#include "interpreter.h"

static int	expand_node(t_astnode *node, t_vector *env);
static int	expand_string(t_vector *str, t_vector *masks, size_t *index,
				t_vector *env);

void debug_print_str_mask(t_vector *str, t_vector *masks, size_t *index, char *msg); //REMOVE

int	expander_launch(t_astnode *node, t_vector *env)
{
	if (!node)
		return (SUCCESS);
	if ((node->type == _CMD || (node->type >= _INPUT && node->type <= _APPEND))
		&& ((expand_node(node, env)
				|| args_vectors_to_stings(&node->args, node->type))))
		return (FAILURE);
	if (expander_launch(node->left, env) || expander_launch(node->right, env))
		return (FAILURE);
	return (SUCCESS);
}

static int	expand_node(t_astnode *node, t_vector *env)
{
	t_vector	*args;
	t_vector	mask;
	size_t		i;

	if (init_interpretation_masks(&mask, node->args))
		return (FAILURE);
	i = 0;
	while (i < node->args->total)
	{
		args = (ft_vector_get(node->args, i));
		if (ft_strpbrk((char *)args->ptr, __INTERPRETERS)
			&& expand_string(node->args, &mask, &i, env))
		{
			ft_vector_free(&mask);
			return (FAILURE);
		}
		i++;
	}
	ft_vector_free(&mask);
	return (SUCCESS);
}

static int	expand_string(t_vector *str, t_vector *masks, size_t *index, t_vector *env)
{
	debug_print_str_mask(str, masks, index, "EXPANDING");
	if (tilde_expansion(str, masks, *index))
		return (FAILURE);
	debug_print_str_mask(str, masks, index, "TILDE");
	if (envars_expansion(str, masks, *index, env))
		return (FAILURE);
	debug_print_str_mask(str, masks, index, "ENVARS");
	if (quote_removal(str, masks, index))
		return (FAILURE);
	debug_print_str_mask(str, masks, index, "QUOTE REMOVAL");
	return (SUCCESS);
}
