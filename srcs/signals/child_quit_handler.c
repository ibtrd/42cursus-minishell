/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_quit_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:01:24 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/03 14:31:38 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <signal.h>

void	child_quit_handler(int sig)
{
	struct sigaction	act;

	(void)sig;
	act.sa_handler = SIG_DFL;
	act.sa_flags = SA_RESTART;
	printf("Quit\n");
	sigaction(SIGQUIT, &act, NULL);
	kill(0, SIGQUIT);
}
