/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parsing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:06:16 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/19 18:56:27 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSING_H
# define MINISHELL_PARSING_H

# include <stdbool.h>

typedef struct s_escape
{
	bool	status;
	bool	single_quote;
	bool	double_quote;
}	t_escape;

int		dup_cmdline(char *cmdline, char **dup);
void	init_escape(t_escape *escape);

#endif