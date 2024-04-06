/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:42:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/06 20:49:44 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "executor.h"
#include "parsing.h"

int	interpreter_routine(t_minishell *minishell, void *color_flag)
{
	char		*input;
	t_astnode	*root;
	int			error;

	error = get_input(minishell, &input, color_flag);
	if (error)
		return (error == EOF);
	root = commandline_parser(input);
	if (!root)
		return (0);
	if (create_here_documents(root))
	{
		free_ast(root);
		if (g_signal)
			minishell->sp_params.exit_status = g_signal + 128;
		else
			minishell->sp_params.exit_status = 1;
		return (0);
	}
	return (executor(root, minishell));
}
