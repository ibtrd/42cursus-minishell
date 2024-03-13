/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:48:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/13 08:13:33 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASK_H
# define MASK_H

typedef struct s_mask
{
	char	c;
	char	m;
}	t_mask;

void	debug_print_mask(void *ptr, size_t index); //REMOVE

#endif //MASK_H