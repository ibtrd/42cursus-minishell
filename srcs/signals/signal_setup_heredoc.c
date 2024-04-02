/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_setup_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:52:34 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/02 19:21:29 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

#include <signal.h>
#include <stddef.h>

int	signal_setup_heredoc(void)
{
	struct sigaction	act;

	act = (struct sigaction){0};
	act.sa_handler = &heredoc_int_handler;
	if (sigaction(SIGINT, &act, NULL) == -1)
		return (1);
	return (0);
}
