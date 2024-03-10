/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_tilde_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:12:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 04:10:06 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "minishelldef.h"
#include "expander.h"

static int	lone_tilde(char **ptr, char **mask);
static int	tilde_plus(char **ptr, char **mask);
static int	tilde_minus(char **ptr, char **mask);
static int	replace_mask(char **ptr, char **mask);

/*
	DESCRIPTION
	The tilde_expansion() expands the '~', '~+' and '~-' word prefixes to
	$HOME, $PWD and $OLDPWD respectively, frees the old string and links
	the resulting one to it's pointer. It also updates the associated
	mask.

	RETURN VALUE
	On succes, 0 is returned. On error, -1 is returned.
*/

int	tilde_expansion(char **ptr, char **mask)
{
	char		*str;

	str = *ptr;
	if (!ft_strncmp(str, "~+", 2))
		return (tilde_plus(ptr, mask));
	if (!ft_strncmp(str, "~-", 2))
		return (tilde_minus(ptr, mask));
	if (!ft_strncmp(str, "~", 1))
		return (lone_tilde(ptr, mask));
	return (SUCCESS);
}

static int	lone_tilde(char **ptr, char **mask)
{
	const char	c = *(*ptr + 1);
	char		*str;

	if (c == '\0')
		str = ft_strdup(__HOME_ENVAR);
	else if (c == '/')
		str = ft_strjoin(__HOME_ENVAR, *ptr + 1);
	else
		return (SUCCESS);
	if (!str)
		return (FAILURE);
	free(*ptr);
	*ptr = str;
	return (replace_mask(ptr, mask));
}

static int	tilde_plus(char **ptr, char **mask)
{
	const char	c = *(*ptr + 2);
	char		*str;

	if (c == '\0')
		str = ft_strdup(__PWD_ENVAR);
	else if (c == '/')
		str = ft_strjoin(__PWD_ENVAR, *ptr + 2);
	else
		return (SUCCESS);
	if (!str)
		return (FAILURE);
	free(*ptr);
	*ptr = str;
	return (replace_mask(ptr, mask));
}

static int	tilde_minus(char **ptr, char **mask)
{
	const char	c = *(*ptr + 2);
	char		*str;

	if (c == '\0')
		str = ft_strdup(__OLDPWD_ENVAR);
	else if (c == '/')
		str = ft_strjoin(__OLDPWD_ENVAR, *ptr + 2);
	else
		return (SUCCESS);
	if (!str)
		return (FAILURE);
	free(*ptr);
	*ptr = str;
	return (replace_mask(ptr, mask));
}

static int	replace_mask(char **ptr, char **mask)
{
	char	*str;

	str = create_string_mask(*ptr);
	if (!str)
		return (FAILURE);
	free(*mask);
	*mask = str;
	return (SUCCESS);
}
