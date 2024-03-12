/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:36:22 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 17:11:09 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* INCLUDES *******************************************************************/

# include "ft_char.h"
# include "ft_integer.h"
# include "ft_lst.h"
# include "ft_mem.h"
# include "ft_misc.h"
# include "ft_string.h"
# include "ft_vector.h"

/* MISC FUNCTIONS *************************************************************/

int		ft_close(int *fd);
void	ft_free_array(void **array);
void	ft_free_2darray_char(char **array);
int		get_next_line(int fd, char **line);

/* FT_PRINTF ******************************************************************/

int		ft_printf(const char *str, ...) \
				__attribute__ ((format (printf, 1, 2)));
int		ft_dprintf(int fd, const char *str, ...) \
				__attribute__ ((format (printf, 2, 3)));

#endif