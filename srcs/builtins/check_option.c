/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:30:28 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/02 16:19:47 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isoption(char c, char *charset)
{
	size_t	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1 << i);
		i++;
	}
	return (0);
}

int	chech_option(char *arg, char *options, char *charset)
{
	size_t	i;
	char	tmp_opt;

	tmp_opt = 0;
	i = 0;
	while (arg[i])
	{
		if (isoption(arg[i], charset))
			tmp_opt |= isoption(arg[i], charset);
		else
			return (1);
		i++;
	}
	*options |= tmp_opt;
	return (0);
}
