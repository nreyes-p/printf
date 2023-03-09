/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreyes-p <nreyes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:48:15 by nreyes-p          #+#    #+#             */
/*   Updated: 2023/01/22 20:04:53 by nreyes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	d = (char *)malloc((len + 1) * sizeof(*s));
	if (d == NULL)
		return (0);
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
