/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signal_msg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:12:14 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/15 17:40:51 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signals.h"
#include "libft.h"

#include <signal.h>
#include <unistd.h>

void	print_signal_msg(void)
{
	if (g_signal == SIGQUIT)
		ft_dprintf(STDERR_FILENO, __QUIT);
	else if (g_signal == SIGINT)
		ft_dprintf(STDERR_FILENO, "\n");
}
