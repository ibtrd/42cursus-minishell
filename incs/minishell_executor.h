/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_executor.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:43:52 by kchillon          #+#    #+#             */
/*   Updated: 2024/02/23 18:09:15 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXECUTOR_H
# define MINISHELL_EXECUTOR_H

# include "minishell_ast.h"

typedef struct s_executor
{
	char	**env;
	char	*program;
	int	in;		// stdin dup(0)
	int	out;	// stdout dup(1)
	int	pipe[2];	// peut etre pas necessaire
	int	background;	// 1 if command is not followed by &&
	int	last_pid;
	int	last_status;
	t_astnode	*node;
}	t_executor;

typedef int	(*t_branching)(t_executor *exec);
typedef int	(*t_open_redirect)(t_executor *exec);

int	branch_logicaloperator(t_executor *exec);
int	branch_redirection(t_executor *exec);
int	open_append(t_executor *exec);
int	open_heredoc(t_executor *exec);
int	open_input(t_executor *exec);
int	open_output(t_executor *exec);

#endif