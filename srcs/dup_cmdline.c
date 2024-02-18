/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_cmdline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:24:34 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/18 21:44:43 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "minishelldef.h"
#include "ft_vector.h"
#include "ft_char.h"
#include "ft_string.h"

int	dup_cmdline(char *cmdline, char **dup)
{
	t_vector		vector;
	int				status;
	int				i;

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
	*dup = ft_strdup(vector.ptr);
	if (*dup)
		status = FAILURE;
	ft_vector_free(&vector);
	return (status);
}
