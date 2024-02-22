/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_ast.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:10:27 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/22 13:57:50 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_AST_H
# define MINISHELL_AST_H

#include "ft_vector.h"

typedef enum e_tokentype
{
	_COMMAND,
	_OPERATOR,
	_PRIO,
	_FILENAME
}	t_tokentype;

typedef enum e_nodetype
{
	_CMD,
	_INPUT,
	_OUTPUT,
	_HEREDOC,
	_APPEND,
	_PIPE,
	_AND,
	_OR
}	t_nodetype;

typedef struct s_astnode
{
	enum e_nodetype		type;
	t_vector			*args;
	struct s_astnode	*left;
	struct s_astnode	*right;
}	t_astnode;

int		ast_newnode(t_astnode **new, t_nodetype type, t_vector *args);
void	free_ast(t_astnode *root);

t_astnode	*ast_addnode(t_astnode *root, t_astnode *new);
t_astnode	*ast_add_logicaloperator(t_astnode *root, t_astnode *new);
t_astnode	*ast_add_pipe(t_astnode *root, t_astnode *new);
t_astnode	*ast_add_redirection(t_astnode *root, t_astnode *new);
t_astnode	*ast_add_command(t_astnode *root, t_astnode *new);

#endif