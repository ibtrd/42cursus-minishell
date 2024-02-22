/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:26:33 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/22 14:30:25 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "minishell_def.h"
#include "libft.h"

static int	tokenizer_init(char **str, char **last);
static int	set_delimiters(char c, char **delimiters);

char	*tokenizer(char *cmdline)
{
	static char	*last = NULL;
	char		*delimiters;
	char		*token;
	int			i;

	if (tokenizer_init(&cmdline, &last) == 1)
		return (NULL);
	token = cmdline;
	i = set_delimiters(*cmdline, &delimiters);
	while (cmdline[i] && !ft_ischarset(cmdline[i], delimiters))
		i++;
	delimiters = __DEFAULT_IFS;
	while (cmdline[i] && !ft_ischarset(cmdline[i], delimiters))
		i++;
	if (!cmdline[i])
	{
		cmdline = NULL;
		last = NULL;
	}
	else
	{
		cmdline[i] = '\0';
		last = cmdline + i + 1;
	}
	return (token);
}

static int	tokenizer_init(char **cmd_line, char **last)
{
	int		i;
	char	*str;

	str = *cmd_line;
	if (!str)
		str = *last;
	if (!str)
		return (1);
	i = 0;
	while (str[i] && ft_ischarset(str[i], __DEFAULT_IFS))
		i++;
	if (!str[i])
	{
		*last = NULL;
		return (1);
	}
	*cmd_line = str + i;
	return (0);
}

static int	set_delimiters(char c, char **delimiters)
{
	if (c == '\'')
	{
		*delimiters = __SINGLE_QUOTE;
		return (1);
	}
	if (c == '\"')
	{
		*delimiters = __DOUBLE_QUOTE;
		return (1);
	}
	*delimiters = __DEFAULT_IFS;
	return (0);
}
