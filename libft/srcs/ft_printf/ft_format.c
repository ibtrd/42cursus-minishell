/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:02:03 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/05 15:21:41 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include "ft_printf.h"

void	pf_init_format_struct(t_format *init)
{
	init->type = '\0';
	init->minus = false;
	init->plus = false;
	init->blank = false;
	init->zero = false;
	init->hash = false;
	init->width = 0;
	init->period = false;
	init->precision = 0;
	init->arglen = 0;
	init->padlen = 0;
	init->precisionlen = 0;
	init->totallen = 0;
}

char	pf_get_type(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && ft_ischarset(str[i], FLAG_SET))
		i++;
	if (str[i] == '*')
		i++;
	else
		while (str[i] && ft_isdigit(str[i]))
			i++;
	if (str[i] && str[i] == '.')
		i++;
	if (str[i] == '*')
		i++;
	else
		while (str[i] && ft_isdigit(str[i]))
			i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] && ft_ischarset(str[i], TYPE_SET))
		return (str[i]);
	return (0);
}

void	pf_format_flags(const char *str, t_format *format)
{
	size_t	i;

	i = 0;
	while (str[i] && ft_ischarset(str[i], FLAG_SET))
	{
		if (str[i] == '-')
			format->minus = true;
		else if (str[i] == '+')
			format->plus = true;
		else if (str[i] == ' ')
			format->blank = true;
		else if (str[i] == '0')
			format->zero = true;
		else if (str[i] == '#')
			format->hash = true;
		i++;
	}
}

void	pf_format_values(const char *str, t_format *format, va_list *args)
{
	size_t	i;

	i = 0;
	while (str[i] && ft_ischarset(str[i], FLAG_SET))
		i++;
	if (str[i] == '*')
	{
		format->width = va_arg(*args, int);
		i++;
	}
	else
	{
		format->width = pf_get_width_value(str + i);
		while (str[i] && ft_isdigit(str[i]))
			i++;
	}
	if (str[i] && str[i] == '.' && str[i + 1] != '-')
	{
		format->period = true;
		i++;
		if (str[i] == '*')
			format->precision = va_arg(*args, int);
		else
			format->precision = pf_get_width_value(str + i);
	}
}

int	pf_get_width_value(const char *width)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (width[i] && ft_isdigit(width[i]))
	{
		if (nbr != 0 && INT_MAX / nbr < 10)
			return (INT_MAX);
		nbr = nbr * 10 + width[i] - '0';
		i++;
	}
	return (nbr);
}
