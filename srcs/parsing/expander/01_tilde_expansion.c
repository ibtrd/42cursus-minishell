/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_tilde_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:12:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 04:44:16 by ibertran         ###   ########lyon.fr   */
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
	t_vector	*str;
	t_vector	*mask;

	str = ft_vector_get(args, index);
	mask = ft_vector_get(masks, index);
	if (!ft_strncmp((char *)str->ptr, "~+", 2))
		return (tilde_sign(str, mask, __PWD_ENVAR));
	if (!ft_strncmp((char *)str->ptr, "~-", 2))
		return (tilde_sign(str, mask, __OLDPWD_ENVAR));
	if (!ft_strncmp((char *)str->ptr, "~", 1))
		return (lone_tilde(str, mask));
	return (SUCCESS);
}

static int	lone_tilde(t_vector *str, t_vector *mask)
{
	const size_t	len = ft_strlen(__HOME_ENVAR);
	const char		next = *(char *)(ft_vector_get(str, 1));
	const char		m = *(char *)(ft_vector_get(mask, 1));

	if (next == '\0' || next == '/')
	{
		if (ft_vector_delete(str, 0)
			|| ft_vector_insertn(str, __HOME_ENVAR, 0, len)
			|| ft_vector_delete(mask, 0)
			|| ft_vector_insertn(mask, __HOME_ENVAR, 0, len)
			|| ft_vector_setn(mask, 0, &m, len))
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	tilde_sign(t_vector *str, t_vector *mask, char *envar)
{
	const size_t	len = ft_strlen(envar);
	const char		next = *(char *)(ft_vector_get(str, 2));
	const char		m = *(char *)(ft_vector_get(mask, 2));

	if (next == '\0' || next == '/')
	{
		if (ft_vector_deleten(str, 0, 2)
			|| ft_vector_insertn(str, envar, 0, len)
			|| ft_vector_deleten(mask, 0, 2)
			|| ft_vector_insertn(mask, envar, 0, len)
			|| ft_vector_setn(mask, 0, &m, len))
			return (FAILURE);
	}
	return (SUCCESS);
}
