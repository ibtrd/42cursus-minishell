/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_expander_launch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:20:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/21 22:11:58 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "parsing.h"

static int	expand_string(t_vector *args, size_t *index, t_minishell *env);

int	expand_node(t_astnode *node, t_minishell *env)
{
	t_vector	*arg;
	size_t		i;

	if (node->type == _HEREDOC)
		return (SUCCESS);
	g_signal = 0;
	i = 0;
	while (i < node->args->total)
	{
		arg = (ft_vector_get(node->args, i));
		if (is_expandable(arg, __INTERPRETERS)
			&& expand_string(node->args, &i, env))
			return (FAILURE);
		i++;
	}
	return (args_vectors_to_stings(&node->args));
}

static int	expand_string(t_vector *args, size_t *index, t_minishell *env)
{
	t_vector	*str;
	int			status;

	str = ft_vector_get(args, *index);
	if (tilde_expansion(str))
		return (FAILURE);
	if (envars_expansion(str, env))
		return (FAILURE);
	status = word_splitting(args, index);
	if (status)
		return (status == FAILURE);
	str = ft_vector_get(args, *index);
	status = filemame_expansion(args, index);
	if (status)
		return (status == FAILURE);
	if (quote_removal(str))
		return (FAILURE);
	return (g_signal != 0);
}
