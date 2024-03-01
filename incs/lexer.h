/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:52:12 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/02 00:32:46 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

#include <ft_vector.h>

enum e_token_type
{
	_AND_TOK,
	_OR_TOK,
	_PIPE_TOK,
	_REDIR_INPUT_TOK,
	_REDIR_OUTPUT_TOK,
	_REDIR_HEREDOC_TOK,
	_REDIR_APPEND_TOK,
	_OPEN_PARENTHESIS_TOK,
	_CLOSE_PARENTHESIS_TOK,
	_CMD_TOK,
	_ARG_TOK,
	_FILE_TOK,
	_INVALID_TOK,
	_END_TOK
};

typedef struct s_lexer_token
{
	enum e_token_type	type;
	char				*value;
}	t_lexer_token;

int	parenthesis_analysis(t_vector *vector, size_t index);

#endif //LEXER_H