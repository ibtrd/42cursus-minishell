/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_executor.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:43:52 by kchillon          #+#    #+#             */
/*   Updated: 2024/02/22 18:58:08 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXECUTOR_H
# define MINISHELL_EXECUTOR_H

typedef struct s_executor
{
	int	in;		// stdin dup(0)
	int	out;	// stdout dup(1)
	int	pipe[2];	// peut etre pas necessaire
	int	background;	// 1 if command is not followed by &&
	int	last_pid;
	int	last_status;
	t_astnode	*node;
}	t_executor;

#endif