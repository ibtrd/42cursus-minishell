/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:02:34 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/03 14:24:09 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

int		ft_rl_event(void);
int		signal_ign_main(void);
int		signal_setup_child(void);
int		signal_setup_heredoc(void);
void	child_int_handler(int sig);
void	child_quit_handler(int sig);
void	heredoc_int_handler(int sig);
void	main_int_handler(int sig);

#endif