/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:14:29 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/20 14:37:52 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"
#include "minishelldef.h"
#include "prompt.h"
#include "minishell.h"

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

int	get_prompt(t_minishell *minishell, char **prompt)
{
	char	*cwd;
	char	*tmp;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		cwd = ft_strdup(__MINISHELL);
	if (!cwd || user_dir(&minishell->env, &cwd))
		return (1);
	tmp = ft_strrchr(cwd, '/');
	if (!tmp)
		*prompt = cwd;
	else if (*(tmp + 1) && *(tmp + 1) != '/')
		*prompt = ft_strrchr(tmp, '/') + 1;
	else
		*prompt = tmp;
	if (minishell->sp_params.exit_status)
		*prompt = ft_sprintf(__PROMPT, __RED, *prompt);
	else
		*prompt = ft_sprintf(__PROMPT, __GREEN, *prompt);
	free(cwd);
	if (!*prompt)
		return (1);
	add_git(&minishell->env, prompt);
	return (!*prompt);
}
