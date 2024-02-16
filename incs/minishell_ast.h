/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_ast.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:10:27 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/16 11:21:04 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_AST_H
# define MINISHELL_AST_H

enum e_nodetype
{
	_COMMAND,
	_AND,
	_OR,
	_PIPE,
	_REDIR_INPUT,
	_REDIR_OUTPUT,
	_REDIR_HEREDOC,
	_REDIR_APPEND
};

typedef struct s_astnode
{
	enum e_nodetype		type;
	char				**argv;
	struct s_astnode	*left;
	struct s_astnode	*right;
}	t_astnode;

#endif