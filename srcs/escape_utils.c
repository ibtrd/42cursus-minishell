/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:43:48 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/19 17:45:25 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parsing.h"

void	init_escape(t_escape *escape)
{
	escape->status = false;
	escape->single_quote = false;
	escape->double_quote = false;
}
