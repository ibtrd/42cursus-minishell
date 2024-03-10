/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:55:05 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/05 22:06:32 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "ast.h"

int	build_command(t_vector **arg_v, t_lexer_token *tok, t_astnode **root)
{
	t_astnode	*new;
	char		*dup;


	if (ft_vector_alloc(arg_v, (t_vinfos){sizeof(char *), 0, ft_vfree}, 1))
		return (FAILURE);
	dup = ft_strdup(tok->value);
	if (!dup)
	{
		ft_vector_dealloc(arg_v, 1);
		return (FAILURE);
	}
	if (ft_vector_add_ptr(*arg_v, dup)
		|| ft_vector_add_ptr(*arg_v, NULL)
		|| ast_newnode(&new, _CMD, *arg_v))
	{
		free(dup);
		ft_vector_dealloc(arg_v, 1);
		return (FAILURE);
	}
	*root = ast_addnode(*root, new);
	return (SUCCESS);
}

int	add_argument(t_vector *arg_v, char *str)
{
	char	*dup;

	dup = ft_strdup(str);
	if (!dup)
		return (FAILURE);
	return (ft_vector_insert_ptr(arg_v, dup, arg_v->total - 1));
}
