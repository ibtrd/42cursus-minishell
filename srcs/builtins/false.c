/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   false.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:30:23 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/14 16:44:25 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	builtin_false(t_executor *exec, char **argv)
{
	(void)exec;
	(void)argv;
	return (1);
}
