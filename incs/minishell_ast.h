/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_ast.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:10:27 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/20 00:24:29 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_AST_H
# define MINISHELL_AST_H

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
	_AND,
	_OR,
	_PIPE,
	_INPUT,
	_OUTPUT,
	_HEREDOC,
	_APPEND
}	t_nodetype;

typedef struct s_astnode
{
	enum e_nodetype		type;
	char				**argv;
	struct s_astnode	*left;
	struct s_astnode	*right;
}	t_astnode;

int		ast_newnode(t_astnode **new, t_nodetype type, char **argv);
void	free_ast(t_astnode *root);

#endif