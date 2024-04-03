/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_here_documents.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:30:07 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/03 14:24:11 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <readline/readline.h>

#include "libft.h"

#include "minishelldef.h"
#include "expander.h"
#include "ast.h"
#include "signals.h"

static int	build_heredoc(t_vector **args);
static int	read_heredoc(t_vector *buffer, char *delimiter);
static	int	set_config(t_vector *arg, char **delimiter, int *expand);

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

	expand = 0;
	if (ft_vector_alloc(&buffer, (t_vinfos){sizeof(char), 0, NULL}, 1))
		return (FAILURE);
	set_config(ft_vector_get(*args, 0), &delimiter, &expand);
	if (signal_setup_heredoc() || read_heredoc(buffer, delimiter))
	{
		free(delimiter);
		ft_vector_dealloc(&buffer, 1);
		signal_setup_main();
		return (FAILURE);
	}
	free(delimiter);
	ft_vector_dealloc(args, 1);
	*args = buffer;
	return (signal_setup_main());
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
