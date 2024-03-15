/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:34:06 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/15 16:54:53 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "env.h"
#include "minishelldef.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int    builtin_pwd(t_executor *exec, char **argv)
{
    char    *pwd;

    (void)argv;
    (void)exec;
    pwd = getcwd(NULL, 0);
    if (!pwd)
    {
        ft_dprintf(2, "%s: pwd: %s\n", __MINISHELL, strerror(errno));
        return (1);
    }
    printf("%s\n", pwd);
    free(pwd);
    return (0);
}
