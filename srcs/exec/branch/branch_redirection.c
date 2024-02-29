/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:01:09 by kchillon          #+#    #+#             */
/*   Updated: 2024/02/23 18:01:34 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_executor.h"
#include "minishell_def.h"

int	branch_redirection(t_executor *exec)
{
	static const t_open_redirect	open_redirect[4] = {open_input, \
														open_output, \
														open_append, \
														open_heredoc};

	if (open_redirect[exec->node->type - _INPUT](exec))
		return (1);
	exec->node = exec->node->right;
	return (node_exec(exec));
}
