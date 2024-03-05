/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:43:52 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/05 14:24:12 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "ast.h"

typedef struct s_executor
{
	char	**env;
	int	in;		// stdin dup(0)
	int	out;	// stdout dup(1)
	int	pipe[2];	// peut etre pas necessaire
	int	background;	// 1 if command is not followed by &&
	int	pid;
	int	last_status;
	t_astnode	*node;
	t_astnode	*root;
}	t_executor;

typedef int	(*t_branching)(t_executor *exec);
typedef int	(*t_open_redirect)(t_executor *exec);

int	branch_command(t_executor *exec);
int	branch_logicaloperator(t_executor *exec);
int	branch_pipe(t_executor *exec);
int	branch_redirection(t_executor *exec);
int	open_append(t_executor *exec);
// int	open_heredoc(t_executor *exec); 7
int	open_input(t_executor *exec);
int	open_output(t_executor *exec);
int	node_exec(t_executor *exec);


#endif