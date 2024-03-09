/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:31:29 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/09 18:47:40 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*ptr;

	ptr = NULL;
	len = ft_strlen(s);
	if (n < len)
		len = n;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr)
		ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}
