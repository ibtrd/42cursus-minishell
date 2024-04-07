/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:32 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/07 14:41:23 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ft_vector.h"
# include "ast.h"

extern int	g_signal;

typedef struct s_minishell
{
	t_vector	env;
	struct s_special_params
	{
		int		exit_status;
		char	*sh_name;
	} sp_params;
}	t_minishell;

int	interpreter_routine(t_minishell *minishell, void *color_flag);

#endif