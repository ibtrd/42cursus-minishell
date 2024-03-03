/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandline_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:49:31 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/03 23:57:59 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ast.h"
#include "parsing.h"

static void	*parser_error(char *ptr);

t_astnode	*commandline_parser(char *input)
{
	char		*cmdline;
	t_vector	lexer;

	if (syntax_checker(input))
		return (parser_error(input));
	if (cmdline_addspace(input, &cmdline))
		return (parser_error(input));
	free(input);
	if (lexer_build(cmdline, &lexer))
		return (parser_error(cmdline));
	if (lexer_analysis(&lexer, 0))
	{
		ft_vector_free(&lexer, NULL);
		return (parser_error(cmdline));
	}
	ft_vector_free(&lexer, NULL);
	free(cmdline);
	return (NULL); //REPLACE WITH AST BUILDING FUNCTION
}

static void	*parser_error(char *ptr)
{
	free(ptr);
	return (NULL);
}
