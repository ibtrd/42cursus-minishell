/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:48:20 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/13 02:57:14 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "stdio.h"

static void	print_vector(t_vector *v, char *msg)
{
	size_t i;

	i = 0;
	printf("\n\n----------------------\n%s\n\n", msg);
	while (i < v->total)
	{
		printf("v[%ld] = %d\n", i, *((int *)ft_vector_get(v, i)));
		i++;
	}
	printf("\n----------------------\n");
}

int main(void)
{
	t_vector 	v;
	t_vector	v2;
	int			i;
	int			elem;

	void		*ptr;

	srand(time(NULL));
	ft_vector_init(&v, (t_vinfos){sizeof(int), 0, NULL});
	i = 0;
	while (i++ < 10)
	{
		elem = rand() % 100;
		ft_vector_add(&v, &elem);
	}
	print_vector(&v, "INIT");
	if (!ft_vector_split(&v, 3, 5, &v2))
	{
		print_vector(&v, "SPLIT1");
		print_vector(&v2, "SPLIT2");
	}
	ft_vector_free(&v);
	ft_vector_free(&v2);
	(void)v2;
	(void)ptr;
}