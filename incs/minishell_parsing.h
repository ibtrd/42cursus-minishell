/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parsing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:06:16 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/23 00:32:52 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSING_H
# define MINISHELL_PARSING_H

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

int		cmdline_addspace(char *cmdline, char **dup);
void	init_escape(t_escape *escape);
char	*cmdline_tokenizer(char *cmdline);

#endif