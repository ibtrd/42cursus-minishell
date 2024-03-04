/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:06:16 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/04 02:20:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>

# include "ft_vector.h"

# include "ast.h"

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

//PARSER
t_astnode	*commandline_parser(char *input);

int		syntax_checker(char *cmdline);
int		cmdline_addspace(char *cmdline, char **dup);
char	*cmdline_tokenizer(char *cmdline);

//LEXER
int		lexer_build(char *cmdline, t_vector *vector);
int		lexer_launch(t_vector *vector, size_t index);

//ESCAPE
void	set_escape_mode(t_escape *escape, char c);
void	init_escape(t_escape *escape);

#endif //PARSING_H