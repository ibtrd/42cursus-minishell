/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_int_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:01:24 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/03 14:31:45 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <signal.h>

void	child_int_handler(int sig)
{
	struct sigaction	act;

	(void)sig;
	act.sa_handler = SIG_DFL;
	act.sa_flags = SA_RESTART;
	printf("\n");
	sigaction(SIGINT, &act, NULL);
	kill(0, SIGINT);
}
