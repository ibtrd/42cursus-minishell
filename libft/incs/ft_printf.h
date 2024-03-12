/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:29:15 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 14:46:08 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <sys/types.h>

# include "ft_vector.h"

typedef int	(*t_convert)(t_vector *, va_list *);

int	add_conversion(char specifier, t_vector *buffer, va_list *args);

#endif //FT_PRINTF_H