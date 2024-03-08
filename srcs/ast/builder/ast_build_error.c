/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 02:20:06 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/08 18:13:03 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "libft.h"

#include "minishelldef.h"
#include "ast.h"

/*
	DESCRIPTION
	The ast_builderror() function prints a message on standard error
	describing the last error encountered during a call to a system or
	library function, then frees the Abstract Syntax Tree pointed to by root

	RETURN VALUE
	The ast_builderror() function returns NULL;
*/

t_astnode	*ast_builderror(t_astnode *root)
{
	ft_dprintf(STDERR_FILENO, "%s: %s: %s\n",
		__MINISHELL,
		__AST_ERROR,
		strerror(errno));
	free_ast(root);
	return (NULL);
}
