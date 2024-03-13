/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector_ian.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:48:20 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/13 05:47:52 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "stdio.h"

int main(void)
{
	t_vector 	v;
	t_vector	v2;
	int			i;
	int			elem;

	srand(time(NULL));
	ft_vector_init(&v, (t_vinfos){sizeof(int), 0, NULL});
	i = 0;
	while (i++ < 10)
	{
		elem = rand() % 20;
		ft_vector_add(&v, &elem);
	}
	printf("INIT\n");
	ft_vector_print(&v, ft_vprint_int);
	if (!ft_vector_split(&v, 3, 5, &v2))
	{
	printf("SPLIT-1\n");
	ft_vector_print(&v, ft_vprint_int);
	printf("SPLIT-2\n");
	ft_vector_print(&v2, ft_vprint_int);
	}

	i = 0;
	while (i < 20)
	{
		printf("SEARCHING %d in v1: %p\n", i, ft_vector_search(&v, &i));
		printf("SEARCHING %d in v2: %p\n", i, ft_vector_search(&v2, &i));
		i++;
	}
	ft_vector_free(&v);
	ft_vector_free(&v2);


	ft_vector_init(&v, (t_vinfos){sizeof(char), 0, NULL});
	ft_vector_join(&v, "pas sur de comp\nrendre t", 26);
	ft_vector_print(&v, ft_vprint_char);
}