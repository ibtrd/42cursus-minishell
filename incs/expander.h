/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:12:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/11 02:50:56 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "ft_vector.h"

//INTERPRETATION MASKS
int	init_interpretation_masks(t_vector *masks, t_vector *args);

//EXPAND
int	tilde_expansion(t_vector *args, t_vector *masks, size_t index);




// int		envars_expansion(char **ptr, char **mask, t_vector *env);
// int		word_splitting(t_vector *args, t_vector *mask, size_t *index);


// int		init_expansion_vectors(t_vector expanded[2], char *str, char *mask);
// int		remove_var_names(t_vector expanded[2], size_t index, char *name);
// int		insert_var_values(t_vector expanded[2], size_t *index, char *value);
// int		replace_vector_pointers(char **ptr, char **mask, t_vector expanded[2]);

#endif //EXPANDER_H