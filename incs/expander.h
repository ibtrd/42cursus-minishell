/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:12:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/20 17:47:58 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "ft_vector.h"

# include "minishell.h"
# include "mask.h"

typedef enum e_wildcard
{
	_INACTIVE,
	_ASTERISK,
	_QUESTION_MARK
}	t_wildcard;

//INTERPRETATION MASKS
t_mask	*str_to_mask(char *str, char mask_value);
char	*mask_to_string(t_vector *arg);

//EXPAND
int		is_expandable(t_vector *arg);

int		tilde_expansion(t_vector *str);
int		envars_expansion(t_vector *str, t_minishell *env);
int		word_splitting(t_vector *args, size_t *index);
int		filemame_expansion(t_vector *args, size_t *index);
int		quote_removal(t_vector *str);

//ENVARS
int		is_special_param(t_vector *str, size_t index, char param,
			t_minishell *env);

//WORD_SPLITTING
int		is_separator(t_mask *mask);
int		is_splittable(t_vector *str);

//FILENAME_EXPANSION
int		is_pattern(t_vector *str);
int		opendir_error(char *dirname);
int		is_match(char *str, t_mask *pat);
int		vsort_masks(void *ptr1, void*ptr2);

//ARGS
int		args_vectors_to_stings(t_vector **args);

#endif //EXPANDER