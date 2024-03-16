/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:14:29 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/16 18:15:41 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"
#include "minishelldef.h"

#include <stdlib.h>
#include <unistd.h>

static int    user_dir(t_vector *env, char **cwd)
{
    char    *home;
    size_t    len;

    home = ft_getenv(env, "HOME");
    if (!home)
	{
        return (0);
	}
    len = ft_strlen(home);
    if (!ft_strncmp(*cwd, home, len) && !(*cwd)[len])
    {
        free(*cwd);
        *cwd = ft_strdup("~");
        if (!*cwd)
            return (1);
    }
    return (0);
}

char	*get_prompt(t_vector *env)
{
	char	*prompt;
	char	*cwd;
	char	*tmp;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		cwd = ft_strdup(__MINISHELL);
	if (!cwd)
		return (NULL);
	if (user_dir(env, &cwd))
		return (NULL);
	tmp = ft_strrchr(cwd, '/');
	if (!tmp)
		prompt = cwd;
	else if (*(tmp + 1) && *(tmp + 1) != '/')
		prompt = ft_strrchr(tmp, '/') + 1;
	else
		prompt = tmp;
	prompt = ft_strjoin2("\e[34m", prompt, "\e[0m ");
	add_git(env, &prompt);
	free(cwd);
	return (prompt);
}
