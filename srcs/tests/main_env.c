/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:41:08 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/15 15:37:03 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "builtins.h"
#include "libft.h"

#include <stdio.h>
#include <stdlib.h>

int    main(int ac, char **av, char **env)
{
    t_vector    envv;
    t_executor    exec;
    int        ret;
    char    *args[8];

    (void)ac;
    (void)av;
    (void)env;
    (void)envv;

    args[0] = ft_strdup("1TRUC=truc");
    args[1] = ft_strdup("_EMPTY");
    args[2] = ft_strdup("OUI=0");
    args[3] = ft_strdup("OU-I=0");
    args[4] = ft_strdup("TRUC=truc");
    args[5] = ft_strdup("OUI=1");
    args[6] = ft_strdup("EMPTY=");
    args[7] = NULL;
    // printf("env: %p\n", env);
    envv = (t_vector){0};
    init_env(&envv, env);
    exec.env = &envv;

	dprintf(2, "envv->total = %zu\n", envv.total);
	dprintf(2, "envv->capacity = %zu\n", envv.capacity);
	dprintf(2, "envv->size = %zu\n", envv.size);
	dprintf(2, "envv->ptr = %p\n", envv.ptr);

    dprintf(2, "ORIGINAL env:\n\n");
    builtin_env(&exec, NULL);
    dprintf(2, "\n\n");
    printf("ft_getenv(envv, \"PATH\") = %s\n", ft_getenv(&envv, "PATH"));
    dprintf(2, "\n\n");
    dprintf(2, "export:\n\n");
    ret = builtin_export(&exec, args);
    dprintf(2, "ret = %d\n", ret);
    dprintf(2, "\n\n");
    dprintf(2, "EXPORT env:\n\n");
    builtin_env(&exec, NULL);
    dprintf(2, "\n\n");
    dprintf(2, "unset:\n\n");
    ret = builtin_unset(&exec, (char *[]){"OUI", "TRUC", "EMPTY", NULL});
    dprintf(2, "ret = %d\n", ret);
    dprintf(2, "\n\n");
    dprintf(2, "UNSET env:\n\n");
    builtin_env(&exec, NULL);

    ft_vector_free(&envv);
    dprintf(2, "\n\n");
    free(args[0]);
    free(args[1]);
    free(args[2]);
    free(args[3]);
    free(args[4]);
    free(args[5]);
    free(args[6]);
    return (0);
}
