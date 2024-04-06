/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 02:20:06 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/06 10:25:34 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "ast.h"
#include "libft.h"
#include "minishelldef.h"

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
	ft_dprintf(STDERR_FILENO, __PARSING_ERROR, __MINISHELL, strerror(errno));
	free_ast(root);
	return (NULL);
}
