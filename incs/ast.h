/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:10:27 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/06 17:42:36 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "ft_vector.h"
# include "lexer.h"

typedef enum e_nodetype
{
	_AND,
	_OR,
	_PIPE,
	_INPUT,
	_OUTPUT,
	_HEREDOC,
	_APPEND,
	_CMD
}	t_nodetype;

typedef struct s_astnode
{
	t_nodetype			type;
	t_vector			*args;
	struct s_astnode	*left;
	struct s_astnode	*right;
}	t_astnode;

int			add_argument(t_vector *arg_v, char *str);
int			ast_newnode(t_astnode **new, t_nodetype type, t_vector *args);
int			build_command(t_vector **arg_v, t_lexer_token *tok,
				t_astnode **root);
int			build_from_token(t_lexer_token *tok, t_astnode **root);
int			build_operator(t_lexer_token *tok, t_astnode **root);
int			build_redirection(t_vector **file_v, t_lexer_token *tok,
				t_astnode **root);
t_astnode	*ast_addleft(t_astnode *root, t_astnode *new);
t_astnode	*ast_addnode(t_astnode *root, t_astnode *new);
t_astnode	*ast_addright(t_astnode *root, t_astnode *new);
t_astnode	*ast_build_brackets(t_astnode *root, t_vector *lexer, int *index);
t_astnode	*ast_builderror(t_astnode *root);
t_astnode	*ast_growleft(t_astnode *root, t_astnode *new);
t_astnode	*ast_growright(t_astnode *root, t_astnode *new);
t_astnode	*free_ast(t_astnode *root);
void		del_args(void	**ptr);

#endif //AST_H