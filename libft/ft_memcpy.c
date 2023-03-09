/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreyes-p <nreyes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:07:54 by nreyes-p          #+#    #+#             */
/*   Updated: 2023/01/22 19:34:57 by nreyes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	const char		*b;
	size_t			i;

	a = dest;
	b = src;
	i = 0;
	if (!a && !b)
		return (dest);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dest);
}
