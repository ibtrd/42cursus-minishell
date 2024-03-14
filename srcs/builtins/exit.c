/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:34:10 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/14 16:36:57 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"

#include <stdlib.h>

int	builtin_exit(t_executor *exec, char **argv)
{
	(void)argv;
	exec_cleanup(exec);
	exit(0);
	return (0);
}