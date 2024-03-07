/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build_launch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:44:13 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/05 22:06:47 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ast.h"

#include "libft.h" //REMOVE
#include "testing.h" //REMOVE

t_astnode	*ast_build_launch(t_vector *lexer)
{
	int				index;
	t_lexer_token	*tok;
	t_astnode		*root;

	root = NULL;
	index = 0;
	tok = ft_vector_get(lexer, index);
	while (tok->type != _END_TOK)
	{
		printf("main loop:	index %d (type %d)\n", index, tok->type);
		if (tok->type == _OPEN_BRACKETS_TOK)
		{
			root = ast_addtree(root, lexer, &index);
			if (!root)
				return (NULL);
		}
		else if (build_from_token(tok, &root))
			return (free_ast(root));
		tok = ft_vector_get(lexer, ++index);
		print2D(2, root, NULL); //REMOVE
	}
	return (root);
}

int	build_from_token(t_lexer_token *tok, t_astnode **root)
{
	static t_vector	*arg_v = NULL;
	static t_vector	*file_v = NULL;

	if (tok->type <= _PIPE_TOK)
		return (build_operator(tok, root));
	if (tok->type <= _REDIR_APPEND_TOK)
		return (build_redirection(&file_v, tok, root));
	if (tok->type == _FILE_TOK)
		return (add_file(file_v, tok->value));
	if (tok->type == _CMD_TOK)
		return (build_command(&arg_v, tok, root));
	if (tok->type == _ARG_TOK)
		return (add_argument(arg_v, tok->value));
	ft_dprintf(2, "BUILDING BAD TOKEN! (Type %d)\n", tok->type); //REMOVE
	return (FAILURE);
}
