/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_setup_child.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:54:25 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/22 18:46:22 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

#include <signal.h>
#include <stddef.h>

# include <stdio.h>

int	signal_setup_child(void)
{
	struct sigaction	act;

	act = (struct sigaction){0};
	act.sa_flags = SA_RESTART;
	act.sa_handler = &child_int_handler;
	if (sigaction(SIGINT, &act, NULL) == -1)
		return (1);
	act.sa_handler = &child_quit_handler;
	if (sigaction(SIGQUIT, &act, NULL) == -1)
		return (1);
	act.sa_handler = SIG_DFL;
	if (sigaction(SIGTERM, &act, NULL) == -1)
		return (1);
	return (0);
}
