/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_signal_msg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:12:14 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/16 14:32:10 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signals.h"
#include "libft.h"

#include <signal.h>
#include <unistd.h>

void	display_signal_msg(void)
{
	if (g_signal == SIGQUIT)
		ft_dprintf(STDERR_FILENO, __QUIT);
	else if (g_signal == SIGINT)
		ft_dprintf(STDERR_FILENO, "\n");
}
