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

#include "minishelldef.h"
#include "ast.h"

#include "unistd.h" //REMOVE

int	build_redirection(t_vector **file_v, t_lexer_token *tok, t_astnode **root)
{
	t_astnode	*new;

	if (ft_vector_alloc(file_v, (t_vinfos){sizeof(t_vector), 1, &del_args}, 1))
		return (FAILURE);
	if (ast_newnode(&new, tok->type, *file_v))
	{
		ft_vector_dealloc(file_v, 1);
		return (FAILURE);
	}
	*root = ast_addnode(*root, new);
	return (SUCCESS);
}

int	add_argument(t_vector *vector, char *str)
{
	const size_t	len = ft_strlen(str) + 1;
	t_vector		dup;

	if (ft_vector_init(&dup, (t_vinfos){sizeof(char), len, NULL}))
		return (FAILURE);
	if (ft_vector_join(&dup, str, len) || ft_vector_add(vector, &dup))
	{
		ft_vector_free(&dup);
		return (FAILURE);
	}
	return (SUCCESS);
}
