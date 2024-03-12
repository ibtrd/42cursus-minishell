/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:29:15 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 16:57:43 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <sys/types.h>

# include "ft_vector.h"

typedef int	(*t_convert)(t_vector *, va_list *);

int	add_conversion(char specifier, t_vector *buffer, va_list *args);
int	pf_build_buffer(const char *str, t_vector *buffer, va_list *args);
int	print_buffer(int fd, t_vector *buffer);

// conversion
int	convert_char(t_vector *buffer, va_list *args);
int	convert_hexlow(t_vector *buffer, va_list *args);
int	convert_hexup(t_vector *buffer, va_list *args);
int	convert_int(t_vector *buffer, va_list *args);
int	convert_percent(t_vector *buffer, va_list *args);
int	convert_string(t_vector *buffer, va_list *args);
int	convert_uint(t_vector *buffer, va_list *args);

#endif //FT_PRINTF_H