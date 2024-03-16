/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_expansion_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:08:15 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/15 23:25:30 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>

#include "libft.h"

#include "minishelldef.h"

int	opendir_error(char *dirname)
{
	ft_dprintf(2, "%s: %s: %s\n", __MINISHELL, dirname, strerror(errno));
	return (FAILURE);
}
