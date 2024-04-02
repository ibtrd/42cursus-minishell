/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_int_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:54:38 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/02 22:14:54 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>

#include "minishell.h"

void	heredoc_int_handler(int sig)
{
	g_signal = sig;
	printf("from handler: %d\n", g_signal);
	rl_pending_input = '\n';
	rl_done = 1;
	// printf("rl_done: %d\n", rl_done);
	// rl_replace_line("", 0);
	rl_on_new_line();
	// rl_redisplay();
}
