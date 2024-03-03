/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_analysis_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:34:39 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/03 04:17:11 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

#include "minishelldef.h"
#include "lexer.h"

int	syntax_error(const char *str)
{
	write(STDERR_FILENO, __PRGM_NAME, __PRGM_NAME_LEN);
	write(STDERR_FILENO, __SYNTAX_ERROR, ft_strlen(__SYNTAX_ERROR));
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "'\n", 2);
	return (FAILURE);
}

int	unsupported_token(const char *str)
{
	write(STDERR_FILENO, __PRGM_NAME, __PRGM_NAME_LEN);
	write(STDERR_FILENO, __UNSUPPORTED_ERROR, ft_strlen(__UNSUPPORTED_ERROR));
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "'\n", 2);
	return (FAILURE);
}
