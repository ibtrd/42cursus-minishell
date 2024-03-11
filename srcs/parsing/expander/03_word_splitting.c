// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   03_word_splitting.c                                :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/03/09 22:53:44 by ibertran          #+#    #+#             */
// /*   Updated: 2024/03/10 05:50:57 by ibertran         ###   ########lyon.fr   */
// /*                                                                            */
// /* ************************************************************************** */

// #include "libft.h"

// #include "minishelldef.h"
// #include "interpreter.h"

// static int	split_str(t_vector *args, t_vector *masks, size_t *index);

// int	word_splitting(t_vector *args, t_vector *masks, size_t *index)
// {
// 	char	*str;
// 	char	*mask;
// 	size_t	i;

// 	str = *((char **)ft_vector_get(args, *index));
// 	mask = *((char **)ft_vector_get(masks, *index));
// 	i = 0;
// 	while (str[i])
// 	{
// 		// ft_dprintf(2, "mask[i] ==%c |  str[i] ==%c\n",mask[i], str[i]);
// 		if (ft_ischarset(str[i], __DEFAULT_IFS) && mask[i] == '$')
// 			return (split_str(args, masks, index));
// 		i++;
// 	}
// 	return (SUCCESS);
// }

// static int	split_str(t_vector *args, t_vector *masks, size_t *index)
// {
// 	const char		*str = *((char **)ft_vector_get(args, *index));
// 	const char		*mask = *((char **)ft_vector_get(masks, *index));
// 	size_t			start;
// 	size_t			end;

// 	if (ft_vector_delete(args, *index, NULL)
// 		|| ft_vector_delete(masks, *index, NULL))
// 		return (FAILURE);
// 	start = 0;
// 	while (str[start])
// 	{
// 		while (ft_ischarset(str[start], __DEFAULT_IFS) && mask[start] == '$')
// 			start++;
// 		end = start;
// 		while (!ft_ischarset(str[start], __DEFAULT_IFS) && mask[start] != '$')
// 			end++;
// 		if ()
// 	}
// 	free(str);
// 	free(mask);
// 	return (SUCCESS);
// }

// static add_word(t_vector *args, t_vector *masks, size_t *index)
// {
	
// }
