/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:41:18 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/14 16:43:41 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

#include "libft.h"
#include "executor.h"

int	builtin_cd(t_executor *exec, char **argv);
int	builtin_echo(t_executor *exec, char **argv);
int	builtin_env(t_executor *exec, char **argv);
int	builtin_exit(t_executor *exec, char **argv);
int	builtin_export(t_executor *exec, char **argv);
int	builtin_false(t_executor *exec, char **argv);
int	builtin_pwd(t_executor *exec, char **argv);
int	builtin_true(t_executor *exec, char **argv);
int	builtin_unset(t_executor *exec, char **argv);
int	chech_option(char *arg, char *options, char *charset);

#endif //BUILTINS_H