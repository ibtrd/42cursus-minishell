/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:44:16 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/07 20:45:24 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "minishell.h"

# define __NOT_A_TTY "%s: %d: Not a tty\n"
# define __INIT_ERROR "%s: Initialisation failure: %s\n"

int	check_ttys(void);
int	init_minishell(t_minishell *minishell, char **old_env, char *sh_name);

#endif