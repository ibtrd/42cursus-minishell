/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build_argument.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:05:29 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/07 18:29:05 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "expander.h"
#include "interpreter.h"
#include "libft.h"

static int	build_mask(t_vector *arg, char *str);

int	add_argument(t_vector *node, char *str)
{
	t_vector		arg;

	if (ft_vector_init(&arg, (t_vinfos){sizeof(t_mask), ft_strlen(str), NULL}))
		return (FAILURE);
	if (build_mask(&arg, str) || ft_vector_add(node, &arg))
	{
		ft_vector_free(&arg);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	build_mask(t_vector *arg, char *str)
{
	t_mask		mask;
	t_escape	quote;
	char		c;

	init_escape(&quote);
	c = *str++;
	while (c)
	{
		set_escape_mode(&quote, c);
		mask.c = c;
		if (quote.mode == _SINGLE && c != '\'')
			mask.m = __SQUOTE_MASK;
		else if (quote.mode == _DOUBLE && c != '\"')
			mask.m = __DQUOTE_MASK;
		else
			mask.m = __NO_MASK;
		if (ft_vector_add(arg, &mask))
			return (FAILURE);
		c = *str++;
	}
	return (ft_vector_add(arg, "\0"));
}
