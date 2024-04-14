/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_tilde_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:12:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/07 19:22:36 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "expander.h"

static int	lone_tilde(t_vector *str);
static int	tilde_sign(t_vector *str, char *envar);

/*
	DESCRIPTION
	The tilde_expansion() expands the '~', '~+' and '~-' word prefixes to
	$HOME, $PWD and $OLDPWD respectively. It also updates the associated
	interpretation mask.

	RETURN VALUE
	On succes, 0 is returned. On error, -1 is returned.
*/

int	tilde_expansion(t_vector *str)
{
	t_mask	*mask;

	mask = ft_vector_get(str, 0);
	if (mask->c != '~')
		return (SUCCESS);
	mask = ft_vector_get(str, 1);
	if (mask->c == '/' || mask->c == '\0')
		return (lone_tilde(str));
	else if (mask->c == '+')
		return (tilde_sign(str, __PWD_ENVAR));
	else if (mask->c == '-')
		return (tilde_sign(str, __OLDPWD_ENVAR));
	return (SUCCESS);
}

static int	lone_tilde(t_vector *str)
{
	t_mask			*insert;

	insert = str_to_mask(__HOME_ENVAR, __NO_MASK);
	if (!insert)
		return (FAILURE);
	if (ft_vector_delete(str, 0)
		|| ft_vector_insertn(str, insert, 0, ft_strlen(__HOME_ENVAR)))
	{
		free(insert);
		return (FAILURE);
	}
	free(insert);
	return (SUCCESS);
}

static int	tilde_sign(t_vector *str, char *envar)
{
	t_mask			*insert;

	insert = str_to_mask(envar, __NO_MASK);
	if (!insert)
		return (FAILURE);
	if (ft_vector_deleten(str, 0, 2)
		|| ft_vector_insertn(str, insert, 0, ft_strlen(envar)))
	{
		free(insert);
		return (FAILURE);
	}
	free(insert);
	return (SUCCESS);
}
