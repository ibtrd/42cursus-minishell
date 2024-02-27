/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:41:40 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/27 18:33:30 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

#include "minishell_parsing.h"

static int	check_quotes(char *cmdline);

int	syntax_checker(char *cmdline)
{
	int	quote;

	quote = check_quotes(cmdline);
	if (quote == 1)
	{
		write(2, "Syntax error: unclosed ' quote\n", 31);
		return (-1);
	}
	if (quote == 2)
	{
		write(2, "Syntax error: unclosed \" quote\n", 31);
		return (-1);
	}
	// if (check_parenthesis(cmdline))
	// {
	// 	write(2, "Syntax error: Unclosed quote\n", 29);
	// 	return (-1);		
	// }
	return (0);

}

static int	check_quotes(char *cmdline)
{
	size_t		i;
	t_escape	escape;
	size_t		single_quotes;
	size_t		double_quotes;

	init_escape(&escape);
	single_quotes = 0;
	double_quotes = 0;
	i = 0;
	while (cmdline[i])
	{
		set_escape_mode(&escape, cmdline[i]);
		if (escape.mode != _DOUBLE && cmdline[i] == '\'')
			single_quotes++;
		else if (escape.mode != _SINGLE && cmdline[i] == '\"')
			double_quotes++;
		i++;
	}
	if (single_quotes % 2)
		return (1);
	if (double_quotes % 2)
		return (2);
	return (0);
}
