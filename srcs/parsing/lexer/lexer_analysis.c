/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:11:23 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/01 22:44:14 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishelldef.h"
#include "lexer.h"
#include "libft.h"

struct s_lexer_data
{
	size_t	open_parenthesis;
	size_t	close_parenthesis;
};

static int	logical_operator_analysis(t_vector *vector, size_t index);
static int	redirection_analysis(t_vector *vector, size_t index);
static int	print_syntax_error(const t_lexer_token *token);

int	lexer_analysis(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	if (ptr->type == _END_TOK)
		return (SUCCESS);
	if (ptr->type == _INVALID_TOK)
		return (print_syntax_error(ptr));
	if (ptr->type >= _REDIR_INPUT_TOK && ptr->type <= _REDIR_APPEND_TOK)
		return (redirection_analysis(vector, index + 1));
	if (ptr->type == _AND_TOK || ptr->type == _OR_TOK)
		return (logical_operator_analysis(vector, index + 1));
	return (lexer_analysis(vector, index + 1));
}

static int	logical_operator_analysis(t_vector *vector, size_t index)
{
	const t_lexer_token	*ptr = ft_vector_get(vector, index);

	if (index == 1)
		return (print_syntax_error(ptr - 1));
	if (ptr->type == _INVALID_TOK)
		return (print_syntax_error(ptr));
	if (ptr->type >= _AND_TOK && ptr->type <= _PIPE_TOK)
		return (print_syntax_error(ptr));
	return (lexer_analysis(vector, index + 1));
}

static int	redirection_analysis(t_vector *vector, size_t index)
{
	t_lexer_token	*ptr;

	ptr = ft_vector_get(vector, index);
	if (!ptr || ptr->type != _CMD_TOK)
		return (print_syntax_error(ptr));
	ptr->type = _FILE_TOK;
	return (lexer_analysis(vector, index + 1));
}

static int	print_syntax_error(const t_lexer_token *token)
{
	write(STDERR_FILENO, __PRGM_NAME, __PRGM_NAME_LEN);
	write(STDERR_FILENO, __SYNTAX_ERROR, ft_strlen(__SYNTAX_ERROR));
	write(STDERR_FILENO, token->value, ft_strlen(token->value));
	write(STDERR_FILENO, "'\n", 2);
	return (FAILURE);
}
