/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector_alloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:54:11 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 17:59:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	t_vector *args;
	char	*str;
	int		i;
	

	if (ft_vector_alloc(&args, (t_vinfos){sizeof(char *), 0, ft_vfree}, 5))
		return (FAILURE);
 
	i = 0;
	while (i < 2500)
	{
		str = ft_itoa(rand());
		ft_vector_add_ptr(args + (rand() % 5), str);
		i++;
	}
	ft_vector_dealloc(&args, 5);
	return (SUCCESS);
}
