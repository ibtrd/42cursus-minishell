/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vectorcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:45:21 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 12:56:17 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int main(void)
{
	t_vector vector;
	int		i;

	ft_vector_init(&vector, (t_vinfos){sizeof(int), 0, NULL});
	i = 48;
	ft_vector_add(&vector, &i);
	i = 58;
	ft_vector_add(&vector, &i);
	i = 23;
	ft_vector_add(&vector, &i);
	i = 42;
	ft_vector_add(&vector, &i);
	i = 200;
	ft_vector_add(&vector, &i);

	int j;
	ft_vector_copy(&vector, 3, &j);
	printf("j = %d\n", j);
	printf("total=%ld\n", vector.total);
	ft_vector_unlink(&vector, 3, &j);
	printf("j = %d\n", j);
	ft_vector_unlink(&vector, 3, &j);
	printf("j = %d\n", j);
	printf("total=%ld\n", vector.total);
}