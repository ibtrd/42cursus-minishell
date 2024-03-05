/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:44:13 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/05 04:59:42 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "lexer.h"
#include "ast.h"

static int	token_to_node(t_lexer_token *tok, t_astnode **new);

t_astnode	*ast_builder(t_vector *lexer)
{
	int				index;
	t_lexer_token	*tok;
	t_astnode		*new;
	t_astnode		*root;

	root = NULL;
	index = 0;
	tok = ft_vector_get(lexer, index++);
	while (tok->type != _END_TOK)
	{
		if (token_to_node(tok, &new))
			return (free_ast(root));

		tok = ft_vector_get(lexer, index++);
	}
	return (root);
}

static int	token_to_node(t_lexer_token *tok, t_astnode **new)
{
	static t_vector	*cmd_v = NULL;
	static t_vector	*file_v = NULL;

	if (tok->type <= _PIPE_TOK && ast_newnode(new, tok->type, NULL))
		return (FAILURE);
	if (tok->type <= _REDIR_APPEND_TOK)
	{
		file_v = malloc(sizeof(t_vector));
		if (!file_v)
			return (FAILURE);
		if (ft_vector_init(file_v, sizeof(char *), 1))
		{
			free(file_v);
			return (FAILURE);
		}
		if (ast_newnode(new, tok->type, file_v))
		{
			ft_vector_free(file_v, NULL);
			return (FAILURE);
		}
		return (SUCCESS);
	}
	if (tok->type == _FILE_TOK)
	{
		if (ft_vector_add_ptr(file_v, tok->value))
			return (FAILURE);
		return (SUCCESS);
	}
	if (tok->type == _CMD_TOK)
	{
		cmd_v = malloc(sizeof(t_vector));
		if (!cmd_v)
			return (FAILURE);
		if (ft_vector_init(cmd_v, sizeof(char *), 4))
		{
			free(cmd_v);
			return (FAILURE);
		}
		if (ast_newnode(new, _CMD, cmd_v))
		{
			ft_vector_free(cmd_v, NULL);
			return (FAILURE);
		}
		return (SUCCESS);
	}
	if (tok->type == _ARG_TOK)
	{
		if (ft_vector_add_ptr(cmd_v, tok->value))
			return (FAILURE);
		return (SUCCESS);
	}
	return (SUCCESS);
}
