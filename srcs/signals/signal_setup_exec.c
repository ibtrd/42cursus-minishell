/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_setup_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:51:28 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/14 18:25:31 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <signal.h>

#include "signals.h"

void	signal_setup_exec(void)
{
	struct sigaction	act;

	act = (struct sigaction){0};
	act.sa_flags = SA_RESTART;
	act.sa_handler = &exec_handler;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
	sigaction(SIGTERM, &act, NULL);
}
