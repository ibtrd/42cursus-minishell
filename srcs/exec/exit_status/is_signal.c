/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:25:09 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/15 15:06:47 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	is_signal(int status)
{
	return ((status >> 9) && 1);
}
