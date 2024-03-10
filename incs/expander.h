/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:12:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 01:41:42 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "ft_vector.h"

int	tilde_expansion(char **ptr);
int	envars_expansion(char **ptr, char **mask, t_vector *env);

int	create_interpreter_mask(t_vector *mask, t_vector *args);

int	init_expansion_vectors(t_vector expanded[2], char *str, char *mask);
int	remove_var_names(t_vector expanded[2], size_t index, char *name);
int	insert_var_values(t_vector expanded[2], size_t *index, char *value);

#endif //EXPANDER_H