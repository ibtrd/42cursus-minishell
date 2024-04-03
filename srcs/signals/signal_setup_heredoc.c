/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_setup_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:52:34 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/03 14:24:13 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stddef.h>
#include <readline/readline.h>

#include "signals.h"

int	signal_setup_heredoc(void)
{
	struct sigaction	act;

	act = (struct sigaction){0};
	act.sa_handler = &heredoc_int_handler;
	if (sigaction(SIGINT, &act, NULL) == -1)
		return (1);
	rl_event_hook=&ft_rl_event;
	return (0);
}
