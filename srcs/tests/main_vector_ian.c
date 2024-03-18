/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector_ian.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:48:20 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/17 04:21:40 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "stdio.h"

int main(void)
{
	t_vector 	v1;
	t_vector	v2;
	int			i;
	int			elem;

	srand(time(NULL));
	ft_vector_init(&v1, (t_vinfos){sizeof(int), 0, NULL});
	i = 0;
	while (i++ < 10)
	{
		elem = rand() % 20;
		ft_vector_add(&v1, &elem);
	}
	ft_vector_print(&v1, ft_vprint_int, "INIT");
	if (!ft_vector_split(&v1, 3, 5, &v2))
	{
	ft_vector_printi(&v1, ft_vprint_int, "SPLIT-1");
	ft_vector_printi(&v2, ft_vprint_int, "SPLIT-2");
	}

	ft_vector_merge(&v1, 0, &v2);
	ft_vector_printi(&v1, ft_vprint_int, "MERGE");
	ft_vector_sort(&v1, ft_vsort_intascend);
	ft_vector_printi(&v1, ft_vprint_int, "SORT");
	ft_vector_free(&v1);
	// i = 0;
	// while (i < 20)
	// {
	// 	printf("SEARCHING %d in v1: %p\n", i, ft_vector_search(&v1, &i));
	// 	printf("SEARCHING %d in v2: %p\n", i, ft_vector_search(&v2, &i));
	// 	i++;
	// }
	// ft_vector_free(&v1);
	// ft_vector_free(&v2);


	// ft_vector_init(&v2, (t_vinfos){sizeof(t_vector), 0, ft_vfree});
	// 	ft_vector_init(&v1, (t_vinfos){sizeof(char), 0, NULL});
	// ft_vector_join(&v1, "pas sur de comp\nrendre t", 26);
	// ft_vector_print(&v1, ft_vprint_char, "TEST CHAR");
	// ft_vector_add(&v2, &v1);
	// 	ft_vector_init(&v1, (t_vinfos){sizeof(char), 0, NULL});
	// ft_vector_join(&v1, "Une autre string", 15);
	// ft_vector_add(&v2, &v1);
	// 	ft_vector_init(&v1, (t_vinfos){sizeof(char), 0, NULL});
	// ft_vector_join(&v1, "UNE 3EME !!", 5);
	// ft_vector_add(&v2, &v1);

	// ft_vector_printi(&v2, ft_vprint_vchar, "VECTOR OF VECTOR");
	// ft_vector_free(&v2);
}