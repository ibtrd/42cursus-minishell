/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:02:34 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/02 19:21:52 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

int		signal_ign_main(void);
int		signal_setup_child(void);
int		signal_setup_heredoc(void);
void	child_int_handler(int sig);
void	child_quit_handler(int sig);
void	heredoc_int_handler(int sig);
void	main_int_handler(int sig);

#endif