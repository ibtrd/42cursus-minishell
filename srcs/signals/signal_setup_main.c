/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_setup_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:54:25 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/03 14:33:51 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stddef.h>
#include <readline/readline.h>

#include "signals.h"

void	signal_setup_main(void)
{
	struct sigaction	act;

	act = (struct sigaction){0};
	act.sa_handler = &main_int_handler;
	act.sa_flags = SA_RESTART;
	sigaction(SIGINT, &act, NULL);
	act.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act, NULL);
	sigaction(SIGTERM, &act, NULL);
	rl_event_hook = NULL;
}
