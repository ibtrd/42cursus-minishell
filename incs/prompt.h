/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:14:51 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/20 14:34:30 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

#include "libft.h"
#include "minishell.h"

int		add_git(t_vector *env, char **prompt);
int		get_prompt(t_minishell *minishell, char **prompt);

#endif