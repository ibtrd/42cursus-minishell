/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:20:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/08 18:15:49 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"
#include "errno.h"

#include "minishelldef.h"

int main(void)
{
	const char *s1 = __PRGM_NAME;
	const char *s2 = __SYNTAX_ERROR;
	const char *token = strerror(errno);
	const char	*null = NULL;

	ft_dprintf(2, "%s: %s: %s %% %c\n", s1, s2, token, '5');
	ft_dprintf(2, "%s: %s: %s %% %c\n", s1, s2, null, '5');
}