/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:06:16 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/07 20:45:44 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>

# include "interpreter.h"
# include "ast.h"

# define __AND "&&"
# define __OR "||"
# define __PIPE "|"
# define __REDIR_INPUT "<"
# define __REDIR_OUTPUT ">"
# define __REDIR_HEREDOC "<<"
# define __REDIR_APPEND ">>"
# define __OPEN_RBRACKET "("
# define __CLOSE_RBRACKET ")"
# define __NEXT_CMD ";"

# define __UNSUPPORTED_OPERATOR1 "<<<"
# define __UNSUPPORTED_OPERATOR2 "<>"
# define __UNSUPPORTED_OPERATOR3 "&"
# define __UNSUPPORTED_OPERATOR4 ";"

# define __DEFAULT_IFS " \t\n"
# define __METACHARACTER "&|<>();"
# define __INTERPRETERS "\"\'$*?~"
# define __QUOTES "\"\'"

# define __SYNTAX_ERROR_STATUS 2

# define __UNEXPECTED_EOF "%s: unexpected EOF while looking for matching `%c'\n"
# define __PARSING_ERROR "%s: Parsing failure: %s\n"

//PARSER
char		*cmdline_tokenizer(char *cmdline);
int			check_quotes(char *cmdline);
int			check_unclosed_input(char *cmdline);
int			cmdline_addspace(char *cmdline, char **dup);
t_astnode	*ast_build(t_vector *lexer);
t_astnode	*commandline_parser(char *input, int *exit_status);

//LEXER
int			lexer_build(char *cmdline, t_vector *vector);
int			lexer_launch(t_vector *vector, size_t index);
void		lexer_set_args(t_vector *lexer);

//ESCAPE
void		set_escape_mode(t_escape *escape, char c);
void		init_escape(t_escape *escape);

int			create_here_documents(t_astnode *root);

#endif //PARSING_H