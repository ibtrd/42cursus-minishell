/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:01:09 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/15 16:45:22 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "expander.h"
#include "libft.h"
#include "minishelldef.h"

#include <stdlib.h>
#include <unistd.h>

static int	open_redirect(t_executor *exec, char *no_expand)
{
	static const t_open_redirect	open_redirect[4] = {open_input, \
														open_output, \
														open_heredoc, \
														open_append};

	if (exec->node->type != _HEREDOC && exec->node->args->total != 2)
	{
		ft_dprintf(STDERR_FILENO, __AMBIGUOUS, __MINISHELL, no_expand);
		return (1);
	}
	return (open_redirect[exec->node->type - _INPUT](exec));
}

int	branch_redirection(t_executor *exec)
{
	t_astnode	*node;
	int			ret;
	char		*no_expand;

	no_expand = NULL;
	if (exec->node->type != _HEREDOC)
	{
		no_expand = mask_to_string(exec->node->args->ptr);
		if (!no_expand)
			return (1);
		ret = expand_node(exec->node, exec->minishell);
		free(no_expand); // BUG: no_expand is freed here, but it is used later in open_redirect
		if (ret)
			return (1);
	}
	ret = open_redirect(exec, no_expand);
	if (ret)
		return (1);
	node = exec->node;
	exec->node = node->right;
	ret = node_exec(exec);
	exec->node = node;
	return (ret);
}
