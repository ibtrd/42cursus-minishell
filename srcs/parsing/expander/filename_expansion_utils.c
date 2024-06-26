/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_expansion_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:08:15 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/22 17:44:30 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <unistd.h>

#include "libft.h"
#include "minishelldef.h"
#include "mask.h"

int	opendir_error(char *dirname)
{
	ft_dprintf(STDERR_FILENO, __ERR, __MINISHELL, dirname, strerror(errno));
	return (FAILURE);
}

int	vsort_masks(void *ptr1, void*ptr2)
{
	const t_mask	*str1 = ((t_vector *)ptr1)->ptr;
	const t_mask	*str2 = ((t_vector *)ptr2)->ptr;
	char			c1;
	char			c2;
	size_t			i;

	i = 0;
	c1 = ft_tolower(str1[i].c);
	c2 = ft_tolower(str2[i].c);
	while (c1 && c2 && c1 == c2)
	{
		i++;
		c1 = ft_tolower(str1[i].c);
		c2 = ft_tolower(str2[i].c);
	}
	return ((c1 - c2) > 0);
}
