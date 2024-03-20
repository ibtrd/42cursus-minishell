/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:45:30 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/20 14:35:41 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "ast.h"

# include <testing.h>
# include <stdio.h>

void	Aprintnode(int fd, t_astnode *node)
{
	const char	*operator[] = {"&&", "||", "|", "<", ">", "<<", ">>"};
	t_vector	*str;
	size_t		i;

	i = 0;
	if (node->type >= _AND && node->type <= _APPEND)
		dprintf(fd, "%s ", operator[node->type]);
	if (node->type == _CMD || (node->type >= _INPUT && node->type <= _APPEND))
	{
		str = ft_vector_get(node->args, i);
		while (i++ < (node->args)->total)
		{
			dprintf(fd, "\e[33m|\e[0m%s\e[33m|\e[0m ", (char *)str->ptr);
			str = ft_vector_get(node->args, i);
		}
	}
	dprintf(fd, "\n");
}

int	node_exec(t_executor *exec)
{
	if (!exec->node)
	{
		// dprintf(2, "node_exec null\n");	// DEBUG
		return (0);
	}
	// Aprintnode(2, exec->node);	// DEBUG
	if (exec->node->type == _AND || exec->node->type == _OR)
		return (branch_logicaloperator(exec));
	if (exec->node->type == _PIPE)
		return (branch_pipe(exec));
	if (exec->node->type >= _INPUT && exec->node->type <= _APPEND)
		return (branch_redirection(exec));
	else
		return (branch_command(exec));
	// dprintf(2, "node_exec not found\n");	// DEBUG
	return (1);
}
