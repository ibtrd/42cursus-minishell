/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:41:18 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/14 15:31:07 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

#include "libft.h"

int	builtin_echo(char **argv);
int	builtin_env(t_vector *env);
int	builtin_export(t_vector *envv, char **argv);
int	builtin_false(void);
int	builtin_true(void);
int	builtin_unset(t_vector *envv, char **argv);
int	chech_option(char *arg, char *options, char *charset);

#endif //BUILTINS_H