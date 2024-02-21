/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:29:15 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/19 17:49:48 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <sys/types.h>
# include <stdbool.h>

typedef struct s_format
{
	int		fd;
	char	type;
	bool	minus;
	bool	plus;
	bool	blank;
	bool	zero;
	bool	hash;
	size_t	width;
	bool	period;
	size_t	precision;
	size_t	arglen;
	size_t	padlen;
	size_t	precisionlen;
	size_t	totallen;
}	t_format;

# define TYPE_SET "cspdiuxX%"
# define FLAG_SET "-+ 0#"

# define FIELD_MAX 0x7FFFFFDE

# define DECIMAL "0123456789"
# define LOWER_HEXA "0123456789abcdef"
# define UPPER_HEXA "0123456789ABCDEF"

char	pf_get_type(const char *str);
int		pf_argument_len(const char *str);
int		pf_convert_percent(int fd);
int		pf_get_width_value(const char *width);
int		pf_place_padding(t_format *format, char	*print);
int		pf_putstr_to_percent(const char *str, int fd);
size_t	pf_decimal_place_sign_left(char *print, t_format *format, int nbr);
size_t	pf_decimal_place_sign(char *print, t_format *format, int nbr);
size_t	pf_place_pointer_prefix(char *print, t_format *format);
ssize_t	pf_convert_char(va_list *args, t_format *format);
ssize_t	pf_convert_decimal(va_list *args, t_format *format);
ssize_t	pf_convert_lower_hexa(va_list *args, t_format *format);
ssize_t	pf_convert_pointer(va_list *args, t_format *format);
ssize_t	pf_convert_string(va_list *args, t_format *format);
ssize_t	pf_convert_unsigned_decimal(va_list *args, t_format *format);
ssize_t	pf_convert_unsigned_decimal(va_list *args, t_format *format);
ssize_t	pf_convert_upper_hexa(va_list *args, t_format *format);
ssize_t	pf_converter(va_list *args, t_format *format);
ssize_t	pf_print_char(t_format *format, char c);
ssize_t	pf_print_decimal_left(t_format *format, int nbr);
ssize_t	pf_print_decimal_zero(t_format *format);
ssize_t	pf_print_decimal(t_format *format, int nbr);
ssize_t	pf_print_lower_hexa_left(t_format *format, int nbr);
ssize_t	pf_print_lower_hexa(t_format *format, int nbr);
ssize_t	pf_print_nil_pointer(t_format *format);
ssize_t	pf_print_null_string(t_format *format);
ssize_t	pf_print_pointer_left(t_format *format, unsigned long long ptr);
ssize_t	pf_print_pointer(t_format *format, unsigned long long ptr);
ssize_t	pf_print_string(t_format *format, char *string);
ssize_t	pf_print_unsigned_decimal_left(t_format *format, unsigned int nbr);
ssize_t	pf_print_unsigned_decimal(t_format *format, unsigned int nbr);
ssize_t	pf_print_upper_hexa_left(t_format *format, int nbr);
ssize_t	pf_print_upper_hexa(t_format *format, int nbr);
ssize_t	pf_reading_head(int fd, const char *str, va_list *args);
void	pf_decimal_maths(t_format *format, int nbr);
void	pf_format_flags(const char *str, t_format *format);
void	pf_format_values(const char *str, t_format*format, va_list *args);
void	pf_init_format_struct(t_format *init);
void	pf_lower_hexa_maths(t_format *format, int nbr);
void	pf_nil_pointer_maths(t_format *format);
void	pf_null_string_maths(t_format *format);
void	pf_pointer_maths(t_format *format, unsigned long long ptr);
void	pf_string_maths(t_format *format, char *string);
void	pf_unsigned_decimal_maths(t_format *format, unsigned int nbr);
void	pf_upper_hexa_maths(t_format *format, int nbr);

#endif