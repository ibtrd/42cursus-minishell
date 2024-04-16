/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandline_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:49:31 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/16 14:23:31 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "libft.h"
#include "minishelldef.h"
#include "parsing.h"

static int	commandline_lexer(char **input, t_vector *lexer);
static int	lexer_failure(char *ptr, char *error);

t_astnode	*commandline_parser(char *input, int *exit_status)
{
	t_vector	lexer;
	t_astnode	*root;

	if (commandline_lexer(&input, &lexer))
	{
		*exit_status = __SYNTAX_ERROR_STATUS;
		return (NULL);
	}
	root = ast_build(&lexer);
	ft_vector_free(&lexer);
	free(input);
	return (root);
}

static int	commandline_lexer(char **input, t_vector *lexer)
{
	char		*cmdline;

	if (cmdline_addspace(*input, &cmdline))
		return (lexer_failure(*input, strerror(errno)));
	free(*input);
	if (lexer_build(cmdline, lexer))
		return (lexer_failure(cmdline, strerror(errno)));
	if (lexer_launch(lexer, 0))
	{
		ft_vector_free(lexer);
		return (lexer_failure(cmdline, NULL));
	}
	lexer_set_args(lexer);
	*input = cmdline;
	return (SUCCESS);
}

static int	lexer_failure(char *ptr, char *error)
{
	free(ptr);
	if (error)
		ft_dprintf(STDERR_FILENO, __PARSING_ERROR, __MINISHELL, error);
	return (FAILURE);
}
