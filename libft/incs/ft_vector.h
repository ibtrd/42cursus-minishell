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
	void			(*del)(void **);
}	t_vector;

typedef struct s_vinfos
{
	size_t			data_size;
	size_t			capacity;
	void			(*del)(void **);
}	t_vinfos;

int		ft_vector_add_ptr(t_vector *v, void *item);
int		ft_vector_add(t_vector *v, void *item);
int		ft_vector_alloc(t_vector **ptr, t_vinfos infos, size_t n);
int		ft_vector_dealloc(t_vector **ptr, size_t n);
int		ft_vector_delete(t_vector *v, size_t index);
int		ft_vector_deleten(t_vector *v, size_t index, size_t n);
int		ft_vector_free(t_vector *v);
int		ft_vector_init(t_vector *v, t_vinfos infos);
int		ft_vector_insert_ptr(t_vector *v, void *item, size_t index);
int		ft_vector_insert(t_vector *v, void *item, size_t index);
int		ft_vector_insertn(t_vector *v, void *item, size_t index, size_t n);
int		ft_vector_join(t_vector *v, void *items, size_t n);
int		ft_vector_replace(t_vector *v, size_t index, void *new);
int		ft_vector_replacen(t_vector *v, size_t index, void *new, size_t n[2]);
int		ft_vector_resize(t_vector *v, size_t capacity);
int		ft_vector_set_ptr(t_vector *v, size_t index, void *item);
int		ft_vector_set(t_vector *v, size_t index, void *item);
int		ft_vector_setn(t_vector *v, size_t index, void *item, size_t n);
int		ft_vector_split(t_vector *v, size_t index, size_t n, t_vector *ptr);
int		ft_vector_strncat(t_vector *v, char *str, size_t len);
int		ft_vector_trim(t_vector *v);
int		ft_vector_unlink(t_vector *v, size_t index, size_t n);
void	*ft_vector_get(t_vector *v, size_t index);

void	ft_vfree(void **var);
void	ft_vclose(void **var);

#endif