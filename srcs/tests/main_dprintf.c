/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:20:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 17:08:03 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"
#include "errno.h"

#include "minishelldef.h"

int main(void)
{
	const char *s1 = __MINISHELL;
	const char *s2 = __SYNTAX_ERROR;
	const char *token = strerror(errno);
	const char	*null = NULL;

	ft_dprintf(2, "%s: %s: %s %% %c\n", s1, s2, token, '5');
	ft_dprintf(2, "%s: %s: %s %% %c\n", s1, s2, null, '5');
	ft_dprintf(2, "%d\n", 42);
	ft_dprintf(2, "%d\n", -42);
	ft_dprintf(2, "%d\n", 0);
	ft_dprintf(2, "%d\n", 2147483647);
	ft_dprintf(2, "%d\n", -2147483648);
	ft_dprintf(2, "%i\n", 42);
	ft_dprintf(2, "%i\n", -42);
	ft_dprintf(2, "%i\n", 0);
	ft_dprintf(2, "%i\n", 2147483647);
	ft_dprintf(2, "%i\n", -2147483648);
	ft_dprintf(2, "%u\n", 42);
	ft_dprintf(2, "%u\n", -42);
	ft_dprintf(2, "%u\n", 0);
	ft_dprintf(2, "%u\n", 2147483647);
	ft_dprintf(2, "%u\n", -2147483648);
	ft_dprintf(2, "%x\n", 42);
	ft_dprintf(2, "%x\n", -42);
	ft_dprintf(2, "%x\n", 0);
	ft_dprintf(2, "%x\n", 2147483647);
	ft_dprintf(2, "%x\n", -2147483648);
	ft_dprintf(2, "%X\n", 42);
	ft_dprintf(2, "%X\n", -42);
	ft_dprintf(2, "%X\n", 0);
	ft_dprintf(2, "%X\n", 2147483647);
	ft_dprintf(2, "%X\n", -2147483648);
	return (0);
}