/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:03:23 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/13 07:47:26 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_H
# define INTERPRETER_H

# include <stdbool.h>

enum e_quote
{
	_NONE,
	_SINGLE,
	_DOUBLE
};

typedef struct s_escape
{
	enum e_quote	mode;
	bool			single_quote;
	bool			double_quote;
}	t_escape;

void	set_escape_mode(t_escape *escape, char c);
void	init_escape(t_escape *escape);

#endif
