/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:43:52 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/16 14:31:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

# include <sys/types.h>

# define __AMBIGUOUS "%s: %s: ambiguous redirect\n"
# define __ERRTERMIOS "%s: termios manipulation failed: %s\n"

typedef struct s_executor
{
	t_minishell	*minishell;
	t_vector	*env;
	int			pid;
	t_astnode	*node;
	t_astnode	*root;
	t_vector	infd;
	t_vector	outfd;
	int			is_main;
}	t_executor;

typedef int	(*t_branching)(t_executor *exec);
typedef int	(*t_open_redirect)(t_executor *exec);
typedef int	(*t_builtin)(t_executor *exec, char **args);

int		apply_redirections(t_executor *exec);
int		branch_command(t_executor *exec);
int		branch_logicaloperator(t_executor *exec);
int		branch_pipe(t_executor *exec);
int		branch_redirection(t_executor *exec);
int		exec_builtins(t_executor *exec, int index);
int		exec_cleanup(t_executor *exec, int ret);
int		expand_node(t_astnode *node, t_minishell *env);
int		get_exit_status(int status);
int		is_signal(int status);
int		node_exec(t_executor *exec);
int		open_append(t_executor *exec);
int		open_heredoc(t_executor *exec);
int		open_input(t_executor *exec);
int		open_output(t_executor *exec);
int		retrieve_status(pid_t pid);
int		search_path(const char *cmd, char **cmd_path, char *path);
void	display_signal_msg(void);

#endif
