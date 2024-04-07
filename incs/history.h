/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:57:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/07 20:12:43 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# define __GLOBAL_HISTORY ".minishell_history"

# define __HISTORY_USAGE "history: usage: history [-c]\n"
# define __HISTORY_INVAL "%s: history: %s: invalid option\n"

void	add_minishell_history(char *str);
char	*get_history_filepath(void);
void	load_global_history(void);

#endif //HISTORY_H