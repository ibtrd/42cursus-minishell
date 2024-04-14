/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_logicaloperator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:08:56 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/14 13:18:22 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	branch_logicaloperator(t_executor *exec)
{
	t_astnode	*node;
	int			ret;

	node = exec->node;
	exec->node = node->left;
	ret = node_exec(exec);
	exec->node = node->right;
	if (node->type == _AND && !ret)
		ret = node_exec(exec);
	exec->minishell->sp_params.exit_status = ret;
	if (ret == FAILURE)
		exec->minishell->sp_params.exit_status = 1;
	else if (node->type == _OR && ret && ret < 128)
		ret = node_exec(exec);
	exec->node = node;
	return (ret);
}
