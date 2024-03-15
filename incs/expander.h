/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:12:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/15 02:13:44 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "ft_vector.h"
# include "ast.h"
# include "mask.h"

//INTERPRETATION MASKS
t_mask	*str_to_mask(char *str, char mask_value);

//EXPAND
int		is_expandable(t_vector *arg);

int		tilde_expansion(t_vector *str);
int		envars_expansion(t_vector *str, t_vector *env);
int		word_splitting(t_vector *args, size_t *index);

//WORD_SPLITTING
int		is_separator(t_mask *mask);
int		is_splittable(t_vector *str);

//ARGS
int		args_vectors_to_stings(t_vector **args);

#endif //EXPANDER_H