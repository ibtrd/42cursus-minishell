/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandline_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:49:31 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/07 02:12:23 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "libft.h"

#include "ast.h"
#include "parsing.h"

#include "testing.h" //REMOVE

static int	commandline_lexer(char **input, t_vector *lexer);
static int	lexer_failure(char *ptr, char *msg);

t_astnode	*commandline_parser(char *input)
{
	t_vector	lexer;
	t_astnode	*root = NULL;

	if (commandline_lexer(&input, &lexer))
		return (NULL);
	lexer_set_args(&lexer);
	root = ast_build_launch(&lexer);
	ft_vector_free(&lexer, NULL);
	print2D(2, root); //REMOVE
	free(input);
	return (root);
}

static int	commandline_lexer(char **input, t_vector *lexer)
{
	char		*cmdline;

	if (syntax_checker(*input))
		return (lexer_failure(*input, NULL));
	if (cmdline_addspace(*input, &cmdline))
		return (lexer_failure(*input, strerror(errno)));
	free(*input);
	if (lexer_build(cmdline, lexer))
		return (lexer_failure(cmdline, strerror(errno)));
	if (lexer_launch(lexer, 0))
	{
		ft_vector_free(lexer, NULL);
		return (lexer_failure(cmdline, NULL));
	}
	*input = cmdline;
	return (SUCCESS);
}

static int	lexer_failure(char *ptr, char *msg)
{
	free(ptr);
	if (msg)
	{
		write(STDERR_FILENO, "minishell: Error: ", 18);
		write(STDERR_FILENO, msg, ft_strlen(msg));
		write(STDERR_FILENO, "\n", 1);
	}
	return (FAILURE);
}
