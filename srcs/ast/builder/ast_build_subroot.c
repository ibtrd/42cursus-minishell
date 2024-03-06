/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build_subroot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:33:09 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/06 22:35:21 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "ast.h"

#	include "libft.h" //REMOVE

int	build_redirection_subroot(t_vector **file_v, t_lexer_token *tok, t_astnode **root);

int	build_token_subroot(t_lexer_token *tok, t_astnode **subroot)
{
	static t_vector	*arg_v = NULL;
	static t_vector	*file_v = NULL;

	if (tok->type <= _PIPE_TOK)
		return (build_operator(tok, subroot));
	if (tok->type <= _REDIR_APPEND_TOK)
		return (build_redirection_subroot(&file_v, tok, subroot));
	if (tok->type == _FILE_TOK)
		return (add_file(file_v, tok->value));
	if (tok->type == _CMD_TOK)
		return (build_command(&arg_v, tok, subroot));
	if (tok->type == _ARG_TOK)
		return (add_argument(arg_v, tok->value));
	ft_dprintf(2, "BUILDING BAD TOKEN (SUBROOT)! (Type %d)\n", tok->type); //REMOVE
	return (FAILURE);
}

int	build_redirection_subroot(t_vector **file_v, t_lexer_token *tok, t_astnode **root)
{
	t_astnode	*new;

	if (ft_vector_allocate(file_v, sizeof(char *), 1))
		return (FAILURE);
	if (ast_newnode(&new, tok->type, *file_v))
	{
		ft_vector_deallocate(file_v, NULL);
		return (FAILURE);
	}
	*root = ast_addnode_subroot(*root, new);
	return (SUCCESS);
}
