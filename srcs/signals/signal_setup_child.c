/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_setup_child.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:54:25 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/14 13:50:29 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stddef.h>

#include "signals.h"

void	signal_setup_child(void)
{
	struct sigaction	act;

	act = (struct sigaction){0};
	act.sa_flags = SA_RESTART;
	act.sa_handler = SIG_DFL;
	// act.sa_handler = &child_int_handler;
	sigaction(SIGINT, &act, NULL);
	// act.sa_handler = &child_quit_handler;
	sigaction(SIGQUIT, &act, NULL);
	sigaction(SIGTERM, &act, NULL);
}
