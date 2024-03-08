/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_tilde_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:12:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/09 00:53:16 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "minishelldef.h"

static int	lone_tilde(char **ptr);
static int	tilde_plus(char **ptr);

int	tilde_expansion(char **ptr)
{
	char		*str;

	str = *ptr;
	if (!ft_strncmp(str, "~+", 2))
		return (tilde_plus(ptr));
	if (!ft_strncmp(str, "~", 1))
		return (lone_tilde(ptr));
	return (SUCCESS);
}

static int	lone_tilde(char **ptr)
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
	return (SUCCESS);
}

static int	tilde_plus(char **ptr)
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
	return (SUCCESS);
}
