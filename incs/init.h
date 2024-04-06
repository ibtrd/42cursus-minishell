/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:44:16 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/06 20:46:10 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

#include "minishell.h"

int	check_ttys(void);
int	init_minishell(t_minishell *minishell, char **old_env, char *sh_name);


#endif