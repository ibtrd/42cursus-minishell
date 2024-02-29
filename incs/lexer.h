/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:52:12 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/29 16:22:12 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

enum e_token_type
{
	_AND_TOK,
	_OR_TOK,
	_PIPE_TOK,
	_REDIR_INPUT_TOK,
	_REDIR_OUTPUT_TOK,
	_REDIR_HEREDOC_TOK,
	_REDIR_APPEND_TOK,
	_PARENTHESIS_OPEN_TOK,
	_PARENTHESIS_CLOSE_TOK,
	_CMD_TOK,
	_ARG_TOK,
	_FILE_TOK,
	_INVALID_TOK
};

typedef struct s_lexer_token
{
	enum e_token_type	type;
	char				*value;
}	t_lexer_token;

#endif //LEXER_H