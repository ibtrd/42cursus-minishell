/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tilde_expansion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:14:47 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/09 01:21:58 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>

#include "expander.h"
#include "libft.h"

int main(void)
{
	char *cmp[] = {"~", "~/", "~/TRUC", "~TRUC", "~+", "~+/", "~+/TRUC", "~+TRUC", NULL };
	char *ptr;

	int i;

	i = 0;
	while (cmp[i])
	{
		ptr = ft_strdup(cmp[i]);
		printf("%10s -> ", ptr);
		tilde_expansion(&ptr);
		printf("%s\n", ptr);
		free(ptr);
		i++;
	}
	return (0);
}
