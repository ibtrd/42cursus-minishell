/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_logicaloperator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:08:56 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/06 16:28:38 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int	branch_logicaloperator(t_executor *exec)
{
	t_astnode	*node;
	int	ret;

	// dprintf(2, "logicaloperator\n");	// DEBUG
	node = exec->node;
	exec->node = node->left;
	ret = node_exec(exec);
	exec->node = node->right;
	if (node->type == _AND && !ret)
		ret = node_exec(exec);
	else if (node->type == _OR && ret)
		ret = node_exec(exec);
	exec->node = node;
	return (ret);
}
