/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:55:05 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/05 22:06:37 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ast.h"

int	build_redirection(t_vector **file_v, t_lexer_token *tok, t_astnode **root)
{
	t_astnode	*new;

	if (ft_vector_alloc(file_v, (t_vinfos){sizeof(void *), 0, ft_vfree}, 1))
		return (FAILURE);
	if (ast_newnode(&new, tok->type, *file_v))
	{
		ft_vector_dealloc(file_v, 1);
		return (FAILURE);
	}
	*root = ast_addnode(*root, new);
	return (SUCCESS);
}

int	add_file(t_vector *file_v, char *str)
{
	char	*dup;

	dup = ft_strdup(str);
	if (!dup)
		return (FAILURE);
	return (ft_vector_add_ptr(file_v, dup));
}
