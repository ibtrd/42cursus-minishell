/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:02:34 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/15 17:39:50 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# define __QUIT "Quit (core dumped)\n"

int		ft_rl_event(void);
void	exec_handler(int sig);
void	main_int_handler(int sig);
void	signal_setup_child(void);
void	signal_setup_exec(void);
void	signal_setup_main(void);
void	signal_setup_pipe(void);

#endif