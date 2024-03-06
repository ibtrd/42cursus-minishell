/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:10:27 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/06 19:32:57 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "ft_vector.h"

# include "lexer.h"

#include <stdio.h> //REMOVE

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

typedef enum e_break
{
	_LOGIC_BREAK,
	_PIPE_BREAK
}	t_break;

int	build_operator(t_lexer_token *tok, t_astnode **root);
int	build_command(t_vector **arg_v, t_lexer_token *tok, t_astnode **root);
int	add_argument(t_vector *arg_v, char *str);
int	build_redirection(t_vector **file_v, t_lexer_token *tok, t_astnode **root);
int	add_file(t_vector *file_v, char *str);

int			ast_newnode(t_astnode **new, t_nodetype type, t_vector *args);
t_astnode	*free_ast(t_astnode *root);

t_astnode	*ast_addnode(t_astnode *root, t_astnode *new);
t_astnode	*ast_add_logicaloperator(t_astnode *root, t_astnode *new);
t_astnode	*ast_add_pipe(t_astnode *root, t_astnode *new);
t_astnode	*ast_add_redirection(t_astnode *root, t_astnode *new);
t_astnode	*ast_add_command(t_astnode *root, t_astnode *new);


//SUBROOT BUILDER
int			build_token_subroot(t_lexer_token *tok, t_astnode **root);
t_astnode	*ast_addnode_subroot(t_astnode *subroot, t_astnode *new);

#endif //AST_H