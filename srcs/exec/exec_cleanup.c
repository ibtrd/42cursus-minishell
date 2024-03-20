/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:38:47 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/20 18:02:16 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

#include <readline/readline.h>

int	exec_cleanup(t_executor *exec)
{
	ft_vector_free(exec->env);
	ft_vector_free(&exec->infd);
	ft_vector_free(&exec->outfd);
	free_ast(exec->root);
	rl_clear_history();
	return (0);
}
