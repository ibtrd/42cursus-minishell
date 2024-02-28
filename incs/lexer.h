/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:52:12 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/28 20:45:34 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

enum e_lex_type
{
	_AND_TOK,
	_OR_TOK,
	_PIPE_TOK,
	_REDIR_INPUT_TOK,
	_REDIR_OUTPUT_TOK,
	_REDIR_HEREDOC_TOK,
	_REDIR_APPEND_TOK,
	_CMD_TOK,
	_FILE_TOK
};

typedef struct s_lex_token
{
	enum e_lex_type	type;
	char			*value;
}	t_lex_token;

#endif //LEXER_H