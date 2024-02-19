/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_cmdline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:24:34 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/19 01:23:04 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "minishell_def.h"
#include "libft.h"

/*
	DESCRIPTION
	The dup_cmdline() add a space character before and after
	each operator, if they are are not already prefixed or suffixed
	by a whitespace character. The resulting string is attached to
	the string pointed by ptr. Memory for the new string is obtained
	with malloc(), and can be freed with free().
	
	RETURN VALUE
	The dup_cmdline() function return 0.
	On error, dup_cmdline() return -1 and the string pointed by ptr
	is set to NULL.
*/

int	dup_cmdline(char *cmdline, char **ptr)
{
	t_vector	vector;
	int			status;
	int			i;

	status = ft_vector_init(&vector, sizeof(char));
	i = 0;
	while (status == SUCCESS && cmdline[i])
	{
		status = ft_vector_add(&vector, cmdline + i);
		if (status == SUCCESS && cmdline[i] != cmdline[i + 1] \
			&& ((!ft_ischarset(cmdline[i], __DEFAULT_IFS) \
			&& ft_ischarset(cmdline[i + 1], __OPERATORS)) \
			|| (ft_ischarset(cmdline[i], __OPERATORS) \
			&& !ft_ischarset(cmdline[i + 1], __DEFAULT_IFS))))
			status = ft_vector_add(&vector, " ");
		i++;
	}
	status = ft_vector_add(&vector, "\0");
	*ptr = ft_strdup(vector.ptr);
	if (*ptr)
		status = FAILURE;
	ft_vector_free(&vector);
	return (status);
}
