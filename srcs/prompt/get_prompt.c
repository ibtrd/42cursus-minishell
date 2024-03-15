/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:14:29 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/15 21:15:14 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"
#include "minishelldef.h"

#include <stdlib.h>
#include <unistd.h>

char	*get_prompt(t_vector *env)
{
	char	*prompt;
	char	*tmp;

	(void)env;
	tmp = getcwd(NULL, 0);
	if (!tmp)
		tmp = ft_strdup(__MINISHELL);
	if (!tmp)
		return (NULL);
	prompt = ft_strjoin2("\e[34m", tmp, "$\e[0m ");
	free(tmp);
	return (prompt);
}
