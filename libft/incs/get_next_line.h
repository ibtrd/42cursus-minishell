/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:09:37 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/20 13:49:05 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# include "libft.h"
# include "ft_vector.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# define GNL_EOF 2
# define GNL 1

int	get_next_line(int fd, char **line);

#endif