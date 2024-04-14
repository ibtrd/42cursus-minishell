/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_launch_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:34:39 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/03 04:17:11 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "lexer.h"
#include "libft.h"
#include "minishelldef.h"

/*
	DESCRIPTION
	The syntax_error() and unsupported_error() print an error message on
	standard error.

	RETURN VALUE
	The syntax_error() and unsupported_error() return -1.
*/

int	syntax_error(const char *token)
{
	ft_dprintf(STDERR_FILENO, __SYNTAX_ERROR, __MINISHELL, token);
	return (FAILURE);
}

int	unsupported_error(const char *token)
{
	ft_dprintf(STDERR_FILENO, __UNSUPPORTED_ERROR, __MINISHELL, token);
	return (FAILURE);
}
