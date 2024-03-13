/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:12:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/13 07:33:40 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "ft_vector.h"
# include "ast.h"

//INTERPRETATION MASKS
int	init_interpretation_masks(t_vector *masks, t_vector *args);

//EXPAND
int	tilde_expansion(t_vector *args, t_vector *masks, size_t index);
int	envars_expansion(t_vector *args, t_vector *masks, size_t index, t_vector *env);
int	quote_removal(t_vector *args, t_vector *masks, size_t *index);
int	word_splitting(t_vector *args, t_vector *masks, size_t *index);

//WORD_SPLITTING
int	is_splittable(t_vector *str, t_vector *mask);
int	is_separator(t_vector *str, t_vector *mask, size_t index);

//ARGS
int	args_vectors_to_stings(t_vector **args, t_nodetype node);

#endif //EXPANDER_H