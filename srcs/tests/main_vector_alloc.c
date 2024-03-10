/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector_alloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:54:11 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 18:55:44 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	t_vector *args;
	char	*str;
	int		i;
	
	srand(time(NULL));
	ft_fmalloc(rand() % 2000);
	if (ft_vector_alloc(&args, (t_vinfos){sizeof(char *), 0, ft_vfree}, 5))
		return (FAILURE);
 
	i = 0;
	while (i < 2500)
	{
		str = ft_itoa(rand());
		if (!str)
			break ;
		if (ft_vector_add_ptr(args + (rand() % 5), str))
		{
			free(str);
			break ;
		}
		i++;
	}
	ft_vector_dealloc(&args, 5);
	return (SUCCESS);
}
