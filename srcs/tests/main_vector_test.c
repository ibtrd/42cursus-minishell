/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:20:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 17:10:07 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "string.h"
#include "errno.h"
#include <stdio.h>
#include <stdlib.h>

void	print_vector(t_vector *v)
{
	size_t	i;
	char	**ptr;

	i = 0;
	// printf("str: |%s|\n", (char *)v->ptr);
	while (i < v->total)
	{
		ptr = ft_vector_get(v, i);
		printf("|%s|\n", *ptr);
		i++;
	}
}

int main(void)
{
	t_vector	v;
	char		*line;
	char		**more;
	
	ft_vector_init(&v, (t_vinfos){sizeof(char *), 0, &ft_vfree});

	line = NULL;
	do
	{
		if (get_next_line(0, &line))
			printf("error\n");
		// printf("|%s|\n", line);
		// if (line)
		// {
		// 	// printf("line: |%s|\n", line);
		// 	// printf("len: %zu\n", ft_strlen(line));
		// 	vector_strncat(&v, line, ft_strlen(line));
		// }
		ft_vector_add_ptr(&v, line);
		// free(line);
	} while (line);

	print_vector(&v);

	printf("-----\n");

	// line = ft_strdup("INSERTqkweijwaie");
	// vector_insert_ptr(&v, line, 1);
	// free(line);

	more = malloc(sizeof(char *) * 3);
	// printf("more: %p\n", more);
	more[0] = ft_strdup("INSERT");
	// printf("more[0]: %p\n", more[0]);
	more[1] = ft_strdup("qkweijwaie");
	// printf("more[1]: %p\n", more[1]);
	more[2] = NULL;
	ft_vector_insertn(&v, more, 1, 3);

	ft_vector_trim(&v);

	print_vector(&v);

	printf("-----\n");

	// vector_delete(&v, 2, &free);
	ft_vector_deleten(&v, 2, 2);

	ft_vector_trim(&v);

	print_vector(&v);

	printf("ptr: %p\n", v.ptr);
	ft_vector_free(&v);
	free(more);

	return (0);
}