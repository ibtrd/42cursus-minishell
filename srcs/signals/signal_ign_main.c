/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_ign_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:59:37 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/22 18:46:29 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

#include <signal.h>
#include <stddef.h>

int	signal_ign_main(void)
{
	struct sigaction	act;

	act = (struct sigaction){0};
	act.sa_handler = SIG_IGN;
	act.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &act, NULL) == -1)
		return (1);
	if (sigaction(SIGQUIT, &act, NULL) == -1)
		return (1);
	if (sigaction(SIGTERM, &act, NULL) == -1)
		return (1);
	return (0);
}
