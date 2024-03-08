/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_expander_launch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:20:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/09 00:18:35 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "ast.h"
#include "env.h"
#include "expander.h"

int	expand_node(t_astnode *node, t_vector *env);
int	expand_str(char **ptr, t_vector *env);

int	expander_launch(t_astnode *node, t_astnode *root, t_vector *env)
{
	if (!node)
		return (SUCCESS);
	if (expand_node(node, env))
		return (FAILURE);
	if (expander_launch(node->left, root, env) || expander_launch(node->right, root, env))
		return (FAILURE);
	return (SUCCESS);
}

int	expand_node(t_astnode *node, t_vector *env)
{
	char	**ptr;
	size_t	i;

	if (node->type != _CMD && !(node->type >= _INPUT && node->type <= _APPEND))
		return (SUCCESS);
	i = 0;
	while (i < node->args->total - (node->type == _CMD))
	{
		ptr = ft_vector_get(node->args, i);
		expand_str(ptr, env);
		i++;
	}
	return (SUCCESS);
	(void)env;
}

int	expand_str(char **ptr, t_vector *env)
{
	// t_vector	expanded;
	char		*str;

	str = *ptr;
	if (!ft_strpbrk(str, __INTERPRETERS))
		return (SUCCESS);
	printf("Need to expand: [%s]\n", str);
	if (tilde_expansion(ptr))
		return (FAILURE);
	return (SUCCESS);
	(void)env;
}


