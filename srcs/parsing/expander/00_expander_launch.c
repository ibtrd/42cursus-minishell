/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_expander_launch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:20:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 04:54:45 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "ast.h"
#include "env.h"
#include "expander.h"
#include "interpreter.h"

static int	to_expand(t_astnode *node);
static int	expand_node(t_astnode *node, t_vector *env);

int	expander_launch(t_astnode *node, t_vector *env)
{
	if (!node)
		return (SUCCESS);
	if (to_expand(node) && expand_node(node, env))
		return (FAILURE);
	if (expander_launch(node->left, env) || expander_launch(node->right, env))
		return (FAILURE);
	return (SUCCESS);
}

static int	to_expand(t_astnode *node)
{
	size_t	i;
	char	**ptr;

	if (node->type != _CMD && (node->type < _INPUT || node->type > _APPEND))
		return (0);
	i = 0;
	while (i < node->args->total - (node->type == _CMD))
	{
		ptr = ft_vector_get(node->args, i);
		if (ft_strpbrk(*ptr, __INTERPRETERS))
			return (1);
		i++;
	}
	return (0);
}

static int	expand_node(t_astnode *node, t_vector *env)
{
	t_vector	mask;
	char		**ptr;
	char		**mask_ptr;
	size_t		i;

	i = 0;
	if (create_interpreter_masks(&mask, node->args))
		return (FAILURE);
	while (i < node->args->total - (node->type == _CMD))
	{
		ptr = ft_vector_get(node->args, i);
		mask_ptr = ft_vector_get(&mask, i);
		ft_dprintf(2, "EXPANDING:\nstr  = %s|\nmask = %s|\n\n", *ptr, *mask_ptr);
		if (tilde_expansion(ptr, mask_ptr))
			return (FAILURE); //PROTECT
		ft_dprintf(2, "TILDE_EXPANSION:\nstr  = %s|\nmask = %s|\n\n", *ptr, *mask_ptr);
		if (envars_expansion(ptr, mask_ptr, env))
			return (FAILURE); //PROTECT
		ft_dprintf(2, "ENVARS_ESPANSION:\nstr  = %s|\nmask = %s|\n\n", *ptr, *mask_ptr);
		if (word_splitting(node->args, &mask, &i))
			return (FAILURE);
		i++;
	}
	ft_vector_free(&mask, ft_vfree);
	return (SUCCESS);
}
