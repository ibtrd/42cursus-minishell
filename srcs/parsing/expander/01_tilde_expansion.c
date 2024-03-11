/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_tilde_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:12:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/11 05:42:06 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "minishelldef.h"

static int	lone_tilde(t_vector *str, t_vector *mask);
static int	tilde_sign(t_vector *str, t_vector *mask, char *envar);

/*
	DESCRIPTION
	The tilde_expansion() expands the '~', '~+' and '~-' word prefixes to
	$HOME, $PWD and $OLDPWD respectively. It also updates the associated
	interpretation mask.

	RETURN VALUE
	On succes, 0 is returned. On error, -1 is returned.
*/

int	tilde_expansion(t_vector *args, t_vector *masks, size_t index)
{
	const t_vector	*str = ft_vector_get(args, index);
	const t_vector	*mask = ft_vector_get(masks, index);

	if (!ft_strncmp((char *)str->ptr, "~+", 2))
		return (tilde_sign((t_vector *)str, (t_vector *)mask, __PWD_ENVAR));
	if (!ft_strncmp((char *)str->ptr, "~-", 2))
		return (tilde_sign((t_vector *)str, (t_vector *)mask, __OLDPWD_ENVAR));
	if (!ft_strncmp((char *)str->ptr, "~", 1))
		return (lone_tilde((t_vector *)str, (t_vector *)mask));
	return (SUCCESS);
}

static int	lone_tilde(t_vector *str, t_vector *mask)
{
	const char		c = *((char *)str->ptr + 1);
	const size_t	len = ft_strlen(__HOME_ENVAR);

	if (c == '\0' || c == '/')
	{
		if (ft_vector_delete(str, 0)
			|| ft_vector_insertn(str, __HOME_ENVAR, 0, len)
			|| ft_vector_delete(mask, 0)
			|| ft_vector_insertn(mask, __HOME_ENVAR, 0, len)
			|| ft_vector_setn(mask, 0, "$", len))
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	tilde_sign(t_vector *str, t_vector *mask, char *envar)
{
	const char		c = *((char *)str->ptr + 2);
	const size_t	len = ft_strlen(envar);

	if (c == '\0' || c == '/')
	{
		if (ft_vector_deleten(str, 0, 2)
			|| ft_vector_insertn(str, envar, 0, len)
			|| ft_vector_deleten(mask, 0, 2)
			|| ft_vector_insertn(mask, envar, 0, len)
			|| ft_vector_setn(mask, 0, "$", len))
			return (FAILURE);
	}
	return (SUCCESS);
}
