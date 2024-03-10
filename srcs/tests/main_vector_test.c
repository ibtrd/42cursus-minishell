/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:20:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 16:54:31 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"
#include "errno.h"

int main(void)
{
	t_vector	v;
	char		*line;
	char		**more;
	
	vector_init(&v, sizeof(char *), 0);

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
		vector_add_ptr(&v, line);
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
	vector_insertn(&v, more, 1, 3);

	vector_trim(&v);

	print_vector(&v);

	printf("-----\n");

	// vector_delete(&v, 2, &free);
	vector_deleten(&v, 2, 2, &ft_vfree);

	vector_trim(&v);

	print_vector(&v);

	printf("ptr: %p\n", v.ptr);
	vector_free(&v, &ft_vfree);
	free(more);

	return (0);
}