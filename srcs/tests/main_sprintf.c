/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:20:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 17:14:48 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "minishelldef.h"

int main(void)
{
	const char *s1 = __MINISHELL;
	const char *s2 = __SYNTAX_ERROR;
	const char *token = strerror(errno);
	const char	*null = NULL;
	char	*str;

	str = ft_sprintf("%s: %s: %s %% %c\n", s1, s2, token, '5');
	printf("%s", str);
	free(str);
	str = ft_sprintf("%s: %s: %s %% %c\n", s1, s2, null, '5');
	printf("%s", str);
	free(str);
	str = ft_sprintf("%d\n", 42);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%d\n", -42);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%d\n", 0);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%d\n", 2147483647);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%d\n", -2147483648);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%i\n", 42);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%i\n", -42);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%i\n", 0);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%i\n", 2147483647);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%i\n", -2147483648);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%u\n", 42);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%u\n", -42);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%u\n", 0);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%u\n", 2147483647);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%u\n", -2147483648);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%x\n", 42);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%x\n", -42);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%x\n", 0);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%x\n", 2147483647);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%x\n", -2147483648);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%X\n", 42);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%X\n", -42);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%X\n", 0);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%X\n", 2147483647);
	printf("%s", str);
	free(str);
	str = ft_sprintf("%X\n", -2147483648);
	printf("%s", str);
	free(str);
	return (0);
}