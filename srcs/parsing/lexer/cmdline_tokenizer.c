/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline_tokenizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:26:33 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/09 22:20:43 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

#include "minishelldef.h"
#include "interpreter.h"

static int		tokenizer_init(char **str, char **last);
static size_t	get_word_end(char *cmdline);

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
	char		*token;
	size_t		i;

	if (tokenizer_init(&cmdline, &last) == 1)
		return (NULL);
	token = cmdline;
	i = get_word_end(cmdline);
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
	char	*str;
	size_t	i;

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

static size_t	get_word_end(char *cmdline)
{
	t_escape	interpreter;
	size_t		i;

	init_escape(&interpreter);
	i = 0;
	while (cmdline[i])
	{
		set_escape_mode(&interpreter, cmdline[i]);
		if (!interpreter.mode && ft_ischarset(cmdline[i], __DEFAULT_IFS))
			return (i);
		i++;
	}
	return (i);
}
