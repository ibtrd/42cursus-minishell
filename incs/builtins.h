/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:41:18 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/07 18:24:29 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "executor.h"

# define __ECHO "echo"
# define __CD "cd"
# define __PWD "pwd"
# define __EXPORT "export"
# define __UNSET "unset"
# define __ENV "env"
# define __EXIT "exit"
# define __HISTORY "history"

//EXIT
# define __EXIT_NUMERIC_ERR "%s: exit: too many arguments\n"
# define __EXIT_ARGS_ERR "%s: exit: %s: numeric argument required\n"

//EXPORT
# define __INVALID_IDENTIFIER "%s: export: `%s': not a valid identifier\n"

//CD
# define __CD_NOT_SET "%s: cd: %s not set\n"
# define __CD_ARGS "%s: cd: too many arguments\n"
# define __CD_ERR "%s: cd: %s: %s\n"

//PWD
# define __PWD_ERR "%s: pwd: %s\n"

int	builtin_cd(t_executor *exec, char **argv);
int	builtin_echo(t_executor *exec, char **argv);
int	builtin_env(t_executor *exec, char **argv);
int	builtin_exit(t_executor *exec, char **argv);
int	builtin_export(t_executor *exec, char **argv);
int	builtin_pwd(t_executor *exec, char **argv);
int	builtin_unset(t_executor *exec, char **argv);
int	builtin_history(t_executor *exec, char **argv);
int	check_option(char *arg, char *options, char *charset);

#endif //BUILTINS_H