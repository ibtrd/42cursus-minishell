/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:20:58 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/15 02:13:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stddef.h>

# define VECTOR_INIT_CAPACITY 16

# define UNDEFINED -1
# define FAILURE -1
# define SUCCESS 0

typedef struct s_vector
{
	void			*ptr;
	size_t			size;
	size_t			capacity;
	size_t			total;
}	t_vector;

int		ft_vector_add_ptr(t_vector *v, void *item);
int		ft_vector_add(t_vector *v, void *item);
int		ft_vector_allocate(t_vector **ptr, size_t data_size, size_t capacity);
int		ft_vector_deallocate(t_vector **ptr, void (*del)(void **));
int		ft_vector_delete(t_vector *v, size_t index, void (*del)(void **));
int		ft_vector_deleten(t_vector *v, size_t index, size_t n, void (*del)(void **));
int		ft_vector_free(t_vector *v, void (*del)(void **));
int		ft_vector_init(t_vector *v, size_t data_size, size_t capacity);
int		ft_vector_insert_ptr(t_vector *v, void *item, size_t index);
int		ft_vector_insert(t_vector *v, void *item, size_t index);
int		ft_vector_insertn(t_vector *v, void *item, size_t index, size_t n);
int		ft_vector_join(t_vector *v, void *items, size_t n);
int		ft_vector_resize(t_vector *v, size_t capacity);
int		ft_vector_set_ptr(t_vector *v, size_t index, void *item);
int		ft_vector_set(t_vector *v, size_t index, void *item);
int		ft_vector_strncat(t_vector *v, char *str, size_t len);
int		ft_vector_trim(t_vector *v);
void	*ft_vector_get(t_vector *v, size_t index);

#endif