/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:02:34 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/03 14:34:12 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

int		ft_rl_event(void);
void	child_int_handler(int sig);
void	child_quit_handler(int sig);
void	heredoc_int_handler(int sig);
void	main_int_handler(int sig);
void	signal_ign_main(void);
void	signal_setup_child(void);
void	signal_setup_heredoc(void);

#endif