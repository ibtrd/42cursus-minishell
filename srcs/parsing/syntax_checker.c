/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:41:40 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/08 05:59:38 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

#include "minishelldef.h"
#include "parsing.h"

static int	check_quotes(char *cmdline);
static int	check_parentheses(char *cmdline);

/*
	DESCRIPTION
	The syntax_checker() function analyse the string pointed by cmdline
	to check if each ' and/or " quote is closed by the the end of the string.
	It then check that no parenthesis is left open by the end of the string.
	On syntax error, the syntax_checker() function print an error
	message on standard error.
	
	RETURN VALUE
	The syntax_checker() function return 0 if no syntax error has been
	detected. On error, syntax_checker() return -1.
*/

int	syntax_checker(char *cmdline)
{
	int	status;

	status = check_quotes(cmdline);
	if (status == __UNCLOSED_SINGLE_QUOTE)
	{
		ft_printf_err(0, "%s: %s `'' quote", __MINISHELL, __UNCLOSED_ERROR);
		return (FAILURE);
	}
	else if (status == __UNCLOSED_DOUBLE_QUOTE)
	{
		ft_printf_err(0, "%s: %s `\"' quote", __MINISHELL, __UNCLOSED_ERROR);
		return (FAILURE);
	}
	status = check_parentheses(cmdline);
	if (status == FAILURE)
	{
		ft_printf_err(0, "%s: %s `'' bracket", __MINISHELL, __UNCLOSED_ERROR);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	check_quotes(char *cmdline)
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
		return (__UNCLOSED_SINGLE_QUOTE);
	if (double_quotes % 2)
		return (__UNCLOSED_DOUBLE_QUOTE);
	return (0);
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
