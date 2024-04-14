/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:52:12 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/07 20:34:26 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <ft_vector.h>

# define __SYNTAX_ERROR "%s: syntax error near unexpected token `%s'\n"
# define __UNSUPPORTED_ERROR "%s: unsupported operator `%s'\n"

enum e_token_type
{
	_AND_TOK = 0,
	_OR_TOK = 1,
	_PIPE_TOK = 2,
	_REDIR_INPUT_TOK = 3,
	_REDIR_OUTPUT_TOK = 4,
	_REDIR_HEREDOC_TOK = 5,
	_REDIR_APPEND_TOK = 6,
	_OPEN_BRACKETS_TOK = 7,
	_CLOSE_BRACKETS_TOK = 8,
	_CMD_TOK = 9,
	_ARG_TOK = 10,
	_FILE_TOK = 11,
	_UNSUPPORTED_TOK = 12,
	_END_TOK = 13
};

typedef struct s_lexer_token
{
	enum e_token_type	type;
	char				*value;
}	t_lexer_token;

typedef enum e_brackets
{
	_NO_BRACKETS,
	_OPENED,
	_CLOSED,
}	t_brackets;

//LEXER_LAUNCH subfunctions
int	lexer_next_tok(t_vector *vector, size_t index, t_brackets mode);
int	lexer_operator_tok(t_vector *vector, size_t index, t_brackets mode);
int	lexer_redirection_tok(t_vector *vector, size_t index, t_brackets mode);
int	lexer_open_bracket(t_vector *vector, size_t index);
int	lexer_close_bracket(t_vector *vector, size_t index);

//LEXER_ERROR
int	syntax_error(const char *token);
int	unsupported_error(const char *token);

#endif //LEXER_H