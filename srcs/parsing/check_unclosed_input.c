/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unclosed_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:41:40 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/06 11:43:53 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	check_parentheses(char *cmdline);

/*
	DESCRIPTION
	The check_unclosed_input() function analyse the string pointed by cmdline
	to check if each ' and " quotes are closed by the the end of the string.
	It then check that no parenthesis is left open by the end of the string.
	
	RETURN VALUE
	The check_unclosed_input() function return 0 if no syntax error has been
	detected. On error, check_unclosed_input() return -1.
*/

int	check_unclosed_input(char *cmdline)
{
	if (check_quotes(cmdline) || check_parentheses(cmdline))
		return (FAILURE);
	return (SUCCESS);
}

int	check_quotes(char *cmdline)
{
	size_t		i;
	t_escape	escape;
	int			single_quotes;
	int			double_quotes;

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
		return ('\'');
	if (double_quotes % 2)
		return ('\"');
	return (SUCCESS);
}

static int	check_parentheses(char *cmdline)
{
	size_t		i;
	t_escape	escape;
	int			parenthesis;

	init_escape(&escape);
	parenthesis = 0;
	i = 0;
	while (cmdline[i])
	{
		set_escape_mode(&escape, cmdline[i]);
		if (!escape.mode && cmdline[i] == '(')
			parenthesis++;
		else if (!escape.mode && cmdline[i] == ')')
			parenthesis--;
		i++;
	}
	if (parenthesis > 0)
		return (FAILURE);
	return (SUCCESS);
}
