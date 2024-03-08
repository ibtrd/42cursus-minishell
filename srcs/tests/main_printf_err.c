/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 04:51:09 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/08 05:28:08 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishelldef.h"
#include "errno.h"

int main(void)
{
	ft_printf_err(errno, "%s: Error de machin", __MINISHELL);
	return (0);
}
