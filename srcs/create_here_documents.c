/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_here_documents.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:30:07 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/06 09:56:47 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>

#include "expander.h"
#include "libft.h"
#include "minishelldef.h"
#include "signals.h"

static int	build_heredoc(t_vector **args);
static int	read_heredoc(t_vector *buffer, char *delimiter);
static int	set_config(t_vector *arg, char **delimiter, int *expand);

/*
	DESCRIPTION
	The create_here_documents() traverses the tree pointed to by root,
	for each node of _HEREDOC type encoutered, it replaces the args vector
	for a new one build from the content of consecutive readline() calls
	up until a string equal to the here document delimiter or an end-of-file
	is encountered.
	
	RETURN VALUE
	The create_here_documents() function returns 0.
	On error, create_here_documents() returns -1.
*/

int	create_here_documents(t_astnode *root)
{
	if (!root)
		return (SUCCESS);
	if ((root->type == _HEREDOC && build_heredoc(&root->args))
		|| create_here_documents(root->left)
		|| create_here_documents(root->right))
		return (FAILURE);
	return (SUCCESS);
}

static int	build_heredoc(t_vector **args)
{
	t_vector	*buffer;
	char		*delimiter;
	int			expand;
	int			status;

	expand = 0;
	if (ft_vector_alloc(&buffer, (t_vinfos){sizeof(char), 0, NULL}, 1))
		return (FAILURE);
	if (set_config(ft_vector_get(*args, 0), &delimiter, &expand))
	{
		ft_vector_dealloc(&buffer, 1);
		return (FAILURE);
	}
	signal_setup_input();
	status = read_heredoc(buffer, delimiter);
	signal_setup_main();
	free(delimiter);
	if (status)
		ft_vector_dealloc(&buffer, 1);
	else
	{
		ft_vector_dealloc(args, 1);
		*args = buffer;
	}
	return (status);
}

static int	read_heredoc(t_vector *buffer, char *delimiter)
{
	char	*line;

	g_signal = 0;
	line = readline(__SECONDARY_PROMPT);
	while (!g_signal && line && ft_strcmp(line, delimiter))
	{
		if (ft_vector_join(buffer, line, ft_strlen(line))
			|| ft_vector_add(buffer, "\n"))
		{
			free(line);
			return (FAILURE);
		}
		free(line);
		line = readline(__SECONDARY_PROMPT);
	}
	if (!line)
		ft_dprintf(STDERR_FILENO, __HEREDOC_EOF, __MINISHELL, delimiter);
	free(line);
	return (g_signal);
}

static	int	set_config(t_vector *arg, char **delimiter, int *expand)
{
	if (is_expandable(arg, __QUOTES))
	{
		if (quote_removal(arg))
			return (FAILURE);
	}
	else
		*expand = 1;
	*delimiter = mask_to_string(arg);
	if (!*delimiter)
		return (FAILURE);
	return (SUCCESS);
}
