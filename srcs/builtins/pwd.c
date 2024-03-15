/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:34:06 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/15 16:40:09 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "env.h"
#include "minishelldef.h"

#include <unistd.h>
#include <stdlib.h>

int    builtin_pwd(t_executor *exec, char **argv)
{
    char    *pwd;

    (void)argv;
    (void)exec;
    pwd = getcwd(NULL, 0);
    if (!pwd)
    {
        ft_dprintf(2, "%s: Cannot get current working directory path\n", __MINISHELL);
        return (1);
    }
    printf("%s\n", pwd);
    free(pwd);
    return (0);
}
