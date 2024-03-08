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

#include "libft.h"

#include "minishelldef.h"

int	syntax_error(const char *str)
{
	ft_printf_err(0, "%s: %s `%s'", __MINISHELL, __SYNTAX_ERROR, str);
	return (FAILURE);
}

int	unsupported_error(const char *str)
{
	ft_printf_err(0, "%s: %s `%s'", __MINISHELL, __UNSUPPORTED_ERROR, str);
	return (FAILURE);
}
