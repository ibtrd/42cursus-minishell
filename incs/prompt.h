/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:14:51 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/07 20:13:13 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "libft.h"
# include "minishell.h"

# define __DEFAULT_PROMPT "\001\e[36;1m\002minishell\001\e[0m\002 "
# define __PROMPT "\001\e[1m\002%s\001\xE2\x86\002\xAA \
\001\e[33m\002%s\001\e[0m\002 "
# define __GIT_PROMPT "%s\001\e[34m\002[%s%s\001\e[34m\002]\001\e[0m\002"
# define __SECONDARY_PROMPT " \001\e[33;1m\002>\001\e[0m\002 "

# define P_WHITE "\001\e[37m\002"
# define P_CYAN "\001\e[36m\002"
# define P_BLUE "\001\e[34m\002"
# define P_YELLOW "\001\e[33m\002"
# define P_GREEN "\001\e[32m\002"
# define P_RED "\001\e[31m\002"	
# define P_BOLD "\001\e[1m\002"
# define P_RESET "\001\e[0m\002"

int		add_git(t_vector *env, char **prompt, void *color_flag);
int		get_prompt(t_minishell *minishell, char **prompt, void *color_flag);

#endif