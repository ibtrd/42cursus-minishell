/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:14:29 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/15 19:36:19 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"

char	*get_prompt(t_vector *env)
{
	char	*prompt;
	char	*tmp;

	tmp = ft_getenv(env, "PWD");
	if (!tmp)
		tmp = ft_getenv(env, "HOME");
	if (!tmp)
		tmp = ft_strdup("minishell");
	if (!tmp)
		return (NULL);
	prompt = ft_strjoin2("\e[34m", tmp, "$\e[0m ");
	return (prompt);
}
