/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:14:29 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/22 12:57:46 by kchillon         ###   ########lyon.fr   */
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

static int	resolve_cwd(t_vector *env, char **cwd)
{
	*cwd = ft_getenv(env, "PWD");
	if (*cwd)
		*cwd = ft_strdup(*cwd);
	if (!*cwd)
		*cwd = getcwd(NULL, 0);
	if (!*cwd)
		*cwd = ft_strdup(__MINISHELL);
	return (!*cwd || user_dir(env, cwd));
}

int	get_prompt(t_minishell *minishell, char **prompt)
{
	char	*cwd;
	char	*tmp;

	if (resolve_cwd(&minishell->env, &cwd))
		return (1);
	tmp = ft_strrchr(cwd, '/');
	if (!tmp)
		*prompt = cwd;
	else if (*(tmp + 1) && *(tmp + 1) != '/')
		*prompt = ft_strrchr(tmp, '/') + 1;
	else
		*prompt = tmp;
	if (minishell->sp_params.exit_status)
		*prompt = ft_sprintf(__PROMPT, P_BOLD, P_RED, *prompt);
	else
		*prompt = ft_sprintf(__PROMPT, P_BOLD, P_GREEN, *prompt);
	free(cwd);
	if (!*prompt)
		return (1);
	add_git(&minishell->env, prompt);
	return (!*prompt);
}
