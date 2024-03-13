/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_str_mask.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 04:16:47 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/13 07:29:58 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "ast.h"
#include "env.h"
#include "expander.h"
#include "interpreter.h"

void debug_print_str_mask(t_vector *args, t_vector *masks, size_t *index, char *msg)
{
	const t_vector	*str = ft_vector_get(args, *index);
	const t_vector	*mask = ft_vector_get(masks, *index);
	size_t			i;
	char			*c;

	ft_dprintf(2, "%s:\nstr  |%s|\nmask |", msg, (char *)str->ptr);
	i = 0;
	while (i < mask->total - 1)
	{
		c = ft_vector_get((t_vector *)mask, i);
		if (*c & __ENVAR_MASK && *c & __DQUOTE_MASK)
			printf("&");
		else if (*c & __ENVAR_MASK)
			printf("$");
		else if (*c & __SQUOTE_MASK)
			printf("\'");
		else if (*c & __DQUOTE_MASK)
			printf("\"");
		else
			printf(".");
		i++;
	}
	printf("|\n\n");
}

void	debug_print_vector_mask(void *ptr, size_t index)
{
	const char	c = *(char *)ptr;

	if (c & __ENVAR_MASK && c & __DQUOTE_MASK)
		printf("&");
	else if (c & __ENVAR_MASK)
		printf("$");
	else if (c & __SQUOTE_MASK)
		printf("\'");
	else if (c & __DQUOTE_MASK)
		printf("\"");
	else
		printf(".");
	(void)index;
}
