/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector_insert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:44:37 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/22 18:21:08 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "ft_vector.h"
#include "libft.h"

void	print_vector(t_vector *v);
void	print_vector_size(t_vector *v);

// int	main(void)
// {
// 	t_vector	vec;
// 	int			tmp;

// 	printf("TESTING VECTOR_INSERT\n\n");

// 	printf("Testing with int\n");
// 	ft_vector_init(&vec, sizeof(int));
// 	tmp = 453;
// 	ft_vector_add(&vec, &tmp);
// 	tmp = 786;
// 	ft_vector_add(&vec, &tmp);
// 	tmp = 1;
// 	ft_vector_add(&vec, &tmp);
// 	tmp = 8637;
// 	ft_vector_add(&vec, &tmp);
// 	tmp = 35474;
// 	ft_vector_add(&vec, &tmp);
// 	tmp = 25;
// 	ft_vector_add(&vec, &tmp);
// 	tmp = 68300;
// 	ft_vector_add(&vec, &tmp);
// 	print_vector(&vec);
// 	tmp = 5555;

// 	printf("\nInserting 5555 at index 1\n");
// 	ft_vector_insert(&vec, &tmp, 1);
// 	print_vector(&vec);
// 	ft_vector_free(&vec);
// 	return (0);
// }

// void	print_vector(t_vector *v)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < v->total)
// 	{
// 		printf("%d\n", *(int *)ft_vector_get(v, i));
// 		i++;
// 	}
// }

int	main(void)
{
	t_vector	vec;

	printf("TESTING VECTOR_INSERT\n\n");

	printf("Testing with char *\n");
	ft_vector_init(&vec, sizeof(char *));
	char str1[] = "catastrophique";
	// *((char **)vec.ptr) = str1;
	// vec.total++;
	ft_vector_add_ptr(&vec, &str1);
	// printf("address of str1: %p\n", str1);
	// printf("address of vec str1: %s\n", *((char **)vec.ptr));
	char str2[] = "-e";
	// *((char **)vec.ptr + 1) = str2;
	// vec.total++;
	ft_vector_add_ptr(&vec, &str2);
	// printf("address of str2: %p\n", str2);
	// printf("address of vec str2: %s\n", *((char **)vec.ptr + 1));
	char str3[] = "<";
	ft_vector_add_ptr(&vec, &str3);
	char str4[] = "|";
	ft_vector_add_ptr(&vec, &str4);
	char str5[] = "head";
	ft_vector_add_ptr(&vec, str5);
	char str6[] = ">";
	ft_vector_add_ptr(&vec, str6);
	char str7[] = "out";
	ft_vector_add_ptr(&vec, str7);
	print_vector_size(&vec);
	print_vector(&vec);

	// printf("\n\nmemory check\n");

	// printf("\nstr1: %p\n", str1);
	// void **truc = ft_vector_get(&vec, 0);
	// printf("vec str1: %p\n", *truc);

	// printf("\nstr2: %p\n", str2);
	// printf("vec str2: %p\n", (char *)ft_vector_get(&vec, 1));

	// printf("\nstr3: %p\n", str3);
	// printf("vec str3: %p\n", (char *)ft_vector_get(&vec, 2));

	// printf("\nstr4: %p\n", str4);
	// printf("vec str4: %p\n", (char *)ft_vector_get(&vec, 3));

	// printf("\nstr5: %p\n", str5);
	// printf("vec str5: %p\n", (char *)ft_vector_get(&vec, 4));

	// printf("\nstr6: %p\n", str6);
	// printf("vec str6: %p\n", (char *)ft_vector_get(&vec, 5));

	// printf("\nstr7: %p\n", str7);
	// printf("vec str7: %p\n", (char *)ft_vector_get(&vec, 6));

	printf("\nInserting \"fizzlepop berrytwist\" at index 2\n");
	char str[] = "fizzlepop berrytwist";
	ft_vector_insert_ptr(&vec, &str, 3);
	// printf("&str=%p\n", str);
	print_vector(&vec);

	printf("\nInserting \"anticonstitutionnelement\" at index 2\n");
	char str0[] = "anticonstitutionnelement";
	ft_vector_insert_ptr(&vec, &str0, 2);
	// printf("&str=%p\n", str);
	print_vector(&vec);

	printf("\nInserting \"Abracadabra\" at index 2\n");
	char str00[] = "Abracadabra";
	ft_vector_insert_ptr(&vec, &str00, 3);
	// printf("&str=%p\n", str);
	print_vector(&vec);

	// printf("\n\nmemory check\n");

	// printf("\nstr: %p\n", str);
	// printf("vec str: %p\n", (char *)ft_vector_get(&vec, 0));
	// printf("str[8]: |%c|\n", str[8]);
	// printf("str + 8: %p\n", str + 8);
	// printf("vec str1[8]: |%c|\n", ((char *)ft_vector_get(&vec, 0))[8]);
	// printf("vec str1 + 8: %p\n", ((char *)ft_vector_get(&vec, 0)) + 8);

	// printf("\nstr1: %p\n", str1);
	// printf("vec str1: %p\n", (char *)ft_vector_get(&vec, 1));
	// printf("str1[3]: |%c|\n", str1[3]);
	// printf("str1 + 3: %p\n", str1 + 3);
	// printf("vec str1[3]: |%c|\n", ((char *)ft_vector_get(&vec, 1))[3]);
	// printf("vec str1 + 3: %p\n", ((char *)ft_vector_get(&vec, 1)) + 3);

	// printf("\nstr1: %p\n", str1);
	// printf("vec str1: %p\n", (char *)ft_vector_get(&vec, 0));

	// printf("\nstr2: %p\n", str2);
	// printf("vec str2: %p\n", (char *)ft_vector_get(&vec, 1));

	// printf("\nstr: %p\n", str);
	// printf("vec str: %p\n", (char *)ft_vector_get(&vec, 2));

	// printf("\nstr3: %p\n", str3);
	// printf("vec str3: %p\n", (char *)ft_vector_get(&vec, 3));

	// printf("\nstr4: %p\n", str4);
	// printf("vec str4: %p\n", (char *)ft_vector_get(&vec, 4));

	// printf("\nstr5: %p\n", str5);
	// printf("vec str5: %p\n", (char *)ft_vector_get(&vec, 5));

	// printf("\nstr6: %p\n", str6);
	// printf("vec str6: %p\n", (char *)ft_vector_get(&vec, 6));

	// printf("\nstr7: %p\n", str7);
	// printf("vec str7: %p\n", (char *)ft_vector_get(&vec, 7));

	// char	*tmp;

	// tmp = (char *)vec.ptr;
	// printf("\n\n");
	// printf("tmp: %s\n", tmp);
	// // printf("*tmp: %s\n", *tmp);
	// // printf("**tmp: %c\n", **tmp);
	// printf("tmp + 1: %p\n", tmp + 1);

	// char ***pache;
	// char **poche;
	// char *piche;
	// piche = ft_strdup("piche");
	// poche = &piche;
	// pache = &poche;
	// printf("piche: %s\n", piche);
	// printf("poche: %s\n", *poche);
	// printf("pache: %s\n", **pache);
	// printf("piche: %p\n", piche);
	// printf("poche: %p\n", *poche);
	// printf("pache: %p\n", **pache);

	ft_vector_free(&vec);
	return (0);
}

void	print_vector(t_vector *v)
{
	size_t	i;

	i = 0;
	while (i < v->total)
	{
		printf("%s\n", *(char **)ft_vector_get(v, i));
		i++;
	}
}

void	print_vector_size(t_vector *v)
{
	printf("size: %zu\n", v->size);
	printf("capacity: %zu\n", v->capacity);
	printf("total: %zu\n", v->total);
	printf("real size: %zu\n", v->size * v->total);
}
