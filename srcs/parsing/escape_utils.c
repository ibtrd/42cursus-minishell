/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:43:48 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/29 00:28:04 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
	DESCRIPTION
	The set_escape_mode() function defines wether a character should be
	escaped while parsing a command line.

	RETURN VALUE
	the set_escape_mode() function return no value.
*/

void	set_escape_mode(t_escape *escape, char c)
{
	if (c == '\"' && !escape->single_quote)
	{
		if (escape->double_quote)
			escape->double_quote = false;
		else
			escape->double_quote = true;
	}
	if (c == '\'' && !escape->double_quote)
	{
		if (escape->single_quote)
			escape->single_quote = false;
		else
			escape->single_quote = true;
	}
	if (escape->double_quote)
		escape->mode = _DOUBLE;
	else if (escape->single_quote)
		escape->mode = _SINGLE;
	else
		escape->mode = _NONE;
}

void	init_escape(t_escape *escape)
{
	escape->mode = _NONE;
	escape->single_quote = false;
	escape->double_quote = false;
}
