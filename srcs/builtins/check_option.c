/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:30:28 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/14 15:32:44 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	chech_option(char *arg, char *options, char *charset)
{
	size_t	i;
	char	tmp_opt;

	tmp_opt = 0;
	i = 0;
	while (arg[i])
	{
		if (!ft_ischarset(arg[i], charset))
			return (1);
		if (arg[i] == 'n')
			tmp_opt |= 1;
		i++;
	}
	*options |= tmp_opt;
	return (0);
}
