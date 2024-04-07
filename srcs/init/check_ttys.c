/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ttys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:41:24 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/06 20:45:05 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishelldef.h"
#include "libft.h"

int	check_ttys(void)
{
	int	in;
	int	out;

	in = !isatty(STDIN_FILENO);
	if (in)
		ft_dprintf(STDERR_FILENO, __NOT_A_TTY, __MINISHELL, STDIN_FILENO);
	out = !isatty(STDOUT_FILENO);
	if (out)
		ft_dprintf(STDERR_FILENO, __NOT_A_TTY, __MINISHELL, STDOUT_FILENO);
	return (in || out);
}
