/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:20:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 17:54:15 by ibertran         ###   ########lyon.fr   */
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

void	test_insertn(t_vector *v)
{
	char **more;

	more = malloc(sizeof(char *) * 3);
	// printf("more: %p\n", more);
	more[0] = ft_strdup("INSERT1");
	// printf("more[0]: %p\n", more[0]);
	more[1] = ft_strdup("INSERT2");
	// printf("more[1]: %p\n", more[1]);
	more[2] = NULL;
	ft_vector_insertn(v, more, 1, 3);

	ft_vector_trim(v);
	
	free(more);
}

void	test_replace(t_vector *v)
{
	char *line;

	line = ft_strdup("REPLACE0123");
	ft_vector_replace(v, 1, &line);
}

void	test_replacen_1(t_vector *v)
{
	char **more;

	
	more = malloc(sizeof(char *) * 3);
	more[0] = ft_strdup("REPLACE1");
	more[1] = ft_strdup("REPLACE2");
	more[2] = ft_strdup("REPLACE3");
	
	ft_vector_replacen(v, 1, more, (size_t[]){2, 3});

	free(more);
}

void	test_replacen_2(t_vector *v)
{
	char **more;

	
	more = malloc(sizeof(char *) * 0);
	// more[0] = ft_strdup("PETIT");
	// more[1] = ft_strdup("REPLACE2");
	// more[2] = ft_strdup("REPLACE3");
	
	// ft_vector_deleten(v, 2, 3);
	ft_vector_replacen(v, 0, more, (size_t[]){6, 0});

	free(more);
}

int main(void)
{
	t_vector	v;
	char		*line;
	
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

	printf("\n----------\n");

	printf("vector_insertn\n\n");

	test_insertn(&v);

	print_vector(&v);

	printf("\n----------\n");

	printf("vector_deleten\n\n");

	ft_vector_deleten(&v, 2, 2);

	ft_vector_trim(&v);

	print_vector(&v);

	printf("\n----------\n");

	printf("vector_replace\n\n");

	test_replace(&v);

	print_vector(&v);

	printf("\n----------\n");

	printf("vector_replacen 1\n\n");

	test_replacen_1(&v);

	print_vector(&v);
	printf("v->total: %zu\n", v.total);
	printf("v->capacity: %zu\n", v.capacity);

	printf("\n----------\n");

	printf("vector_add 1\n\n");

	ft_vector_add_ptr(&v, ft_strdup("ADD012345678"));

	print_vector(&v);

	printf("\n----------\n");

	printf("vector_replacen 2\n\n");

	test_replacen_2(&v);

	print_vector(&v);
	printf("v->total: %zu\n", v.total);
	printf("v->capacity: %zu\n", v.capacity);

	printf("\n----------\n");

	printf("vector_free\n\n");

	printf("ptr: %p\n", v.ptr);
	ft_vector_free(&v);

	return (0);
}

