/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:32:47 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/15 16:10:03 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <sys/wait.h>

int	retrieve_status(pid_t pid)
{
	int	status;

	pid = waitpid(pid, &status, 0); // PROTECT
	if (pid == -1 && errno != ECHILD)
		return (1);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128 + 0x200);
	return (1);
}
