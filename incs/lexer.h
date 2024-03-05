/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:52:12 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/04 03:46:44 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <ft_vector.h>

enum e_token_type
{
	_AND_TOK,
	_OR_TOK,
	_PIPE_TOK,
	_REDIR_INPUT_TOK,
	_REDIR_OUTPUT_TOK,
	_REDIR_HEREDOC_TOK,
	_REDIR_APPEND_TOK,
	_OPEN_BRACKETS_TOK,
	_CLOSE_BRACKETS_TOK,
	_CMD_TOK,
	_ARG_TOK,
	_FILE_TOK,
	_UNSUPPORTED_TOK,
	_END_TOK
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
int	syntax_error(const char *str);
int	unsupported_error(const char *str);

#endif //LEXER_H