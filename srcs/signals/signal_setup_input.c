/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_setup_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:52:34 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/07 19:31:03 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <signal.h>

#include "signals.h"

void	signal_setup_input(void)
{
	struct sigaction	act;

	act = (struct sigaction){0};
	act.sa_handler = &input_int_handler;
	sigaction(SIGINT, &act, NULL);
	rl_event_hook = &ft_rl_event;
}
