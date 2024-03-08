/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 02:20:06 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/08 03:06:46 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishelldef.h"
#include "ast.h"

/*
	DESCRIPTION
	The ast_builderror() function frees the Abstract Syntax Tree pointed
	to by root, then produces a message on standard error describing the
	last error encountered during a call to a system or library function.

	RETURN VALUE
	The ast_builderror() function returns NULL;
*/

t_astnode	*ast_builderror(t_astnode *root)
{
	free_ast(root);
	perror("minishell: AST building failed: ");
	return (NULL);
}
