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

#include "ast.h"

int	build_command(t_vector **arg_v, t_lexer_token *tok, t_astnode **root)
{
	t_astnode	*new;

	if (ft_vector_alloc(arg_v, (t_vinfos){sizeof(t_vector), 2, del_args}, 1))
		return (FAILURE);
	if (add_argument(*arg_v, tok->value) || ast_newnode(&new, _CMD, *arg_v))
	{
		ft_vector_dealloc(arg_v, 1);
		return (FAILURE);
	}
	*root = ast_addnode(*root, new);
	return (SUCCESS);
}
