/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:43:52 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/06 18:15:33 by kchillon         ###   ########lyon.fr   */
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
	int	pid;
	t_astnode	*node;
	t_astnode	*root;
	t_vector	infd;
	t_vector	outfd;
}	t_executor;

typedef int	(*t_branching)(t_executor *exec);
typedef int	(*t_open_redirect)(t_executor *exec);

int		branch_command(t_executor *exec);
int		branch_logicaloperator(t_executor *exec);
int		branch_pipe(t_executor *exec);
int		branch_redirection(t_executor *exec);
int		open_append(t_executor *exec);
// int	open_heredoc(t_executor *exec); 7
int		open_input(t_executor *exec);
int		open_output(t_executor *exec);
int		node_exec(t_executor *exec);
void	close_fds(t_executor *exec);

void	printf_redir(t_executor *exec);	// DEBUG

#endif