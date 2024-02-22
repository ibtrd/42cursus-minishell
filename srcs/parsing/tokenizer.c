/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:26:33 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/22 13:22:07 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "minishell_def.h"
#include "libft.h"

#include <stdio.h> //REMOVE
// static char	*set_delimiters(char *c, char **cmdline);

char	*tokenizer(char *cmdline)
{
	static char	*last = NULL;
	char		*delimiters;
	char		*token;
	int			i;

	if (!cmdline)
		cmdline = last;
	if (!cmdline)
		return (NULL);
	i = 0;
	while (cmdline[i] && ft_ischarset(cmdline[i], __DEFAULT_IFS))
		i++;
	if (!cmdline[i])
	{
		last = NULL;
		return (NULL);
	}
	if (cmdline[i] == '\'')
	{
		delimiters = "\'";
		token = cmdline + i;
		i++;
	}
	else if (cmdline[i] == '\"')
	{
		delimiters = "\"";
		token = cmdline + i;
		i++;
	}
	else
	{
		delimiters = __DEFAULT_IFS;
		token = cmdline + i;
	}
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
		if (cmdline[i] == '\'' || cmdline[i] == '\"')
			i++;
		cmdline[i] = '\0';
		last = cmdline + i + 1;
	}
	return (token);
}

// static char	*set_delimiters(char *c, char **cmdline)
// {
// 	if (*c == '\'')
// 	{
// 		*c = **cmdline;
// 		(*cmdline)++;
// 		return ("\'");
// 	}
// 	return (__DEFAULT_IFS);
// }

// static char	*d



