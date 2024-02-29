/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline_tokenizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:26:33 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/28 20:41:21 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "minishelldef.h"
#include "libft.h"

static int	tokenizer_init(char **str, char **last);
static int	tokenizer_set_delimiters(char c, char **delimiters);

/*
	DESCRIPTION
	The cmdline_tokenizer() function breaks a string into a sequence of zero
	or more nonempty tokens. On the first call to cmdline_tokenizer(),
	the string to be parsed should be specified in str. In each subsequent
	call that should parse the same string, str must be NULL.
	
	RETURN VALUE
	The cmdline_tokenizer() function return a pointer to the next token,
	or NULL if there are no more tokens.
*/

char	*cmdline_tokenizer(char *cmdline)
{
	static char	*last = NULL;
	char		*delimiters;
	char		*token;
	int			i;

	if (tokenizer_init(&cmdline, &last) == 1)
		return (NULL);
	token = cmdline;
	i = tokenizer_set_delimiters(*cmdline, &delimiters);
	while (cmdline[i] && !ft_ischarset(cmdline[i], delimiters))
		i++;
	delimiters = __DEFAULT_IFS;
	while (cmdline[i] && !ft_ischarset(cmdline[i], delimiters))
		i++;
	if (!cmdline[i])
		last = NULL;
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

static int	tokenizer_set_delimiters(char c, char **delimiters)
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
