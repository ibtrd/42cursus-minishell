/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:32 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/23 17:44:46 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ft_vector.h"
# include "ast.h"

typedef struct s_minishell
{
	t_vector	env;
	struct s_special_params
	{
		int		exit_status;
		char	*sh_name;
	} sp_params;
}	t_minishell;

int		get_input(t_minishell *minishell, char **input);
int		search_path(const char *cmd, char **cmd_path, char *path);
int		expand_node(t_astnode *node, t_minishell *env);
int		signal_setup_main(void);
void	minishell_add_history(char *str);
void	init_history(void);

#endif