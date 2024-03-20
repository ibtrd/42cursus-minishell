/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandline_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:49:31 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/20 16:00:49 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "libft.h"

#include "minishelldef.h"
#include "ast.h"
#include "parsing.h"

static int	commandline_lexer(char **input, t_vector *lexer);
static int	lexer_failure(char *ptr, char *error);

t_astnode	*commandline_parser(char *input, t_minishell *env)
{
	t_vector	lexer;
	t_astnode	*root;

	if (commandline_lexer(&input, &lexer))
		return (NULL);
	root = ast_build(&lexer);
	ft_vector_free(&lexer);
	if (expander_launch(root, env))
		return (NULL); //ADD FREE FUNCTION
	#ifdef PRINT
	dprint_ast(2, root, NULL); //REMOVE
	#endif
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
		ft_dprintf(STDERR_FILENO, "%s: Error: %s\n", __MINISHELL, error);
	return (FAILURE);
}
