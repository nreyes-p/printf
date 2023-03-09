/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreyes-p <nreyes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:06:11 by nreyes-p          #+#    #+#             */
/*   Updated: 2023/01/26 20:21:02 by nreyes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_getintlen(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
		n *= -1;
	if (n < 10)
		return (i);
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_doitoa(long int x, int len, int sign, char *res)
{
	res[len] = 0;
	while (x >= 0 && (len - sign) > 0)
	{
		res[--len] = (x % 10) + 48;
		x /= 10;
	}
	if (sign == 1)
		res[--len] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			len;
	int			sign;
	long int	x;

	sign = 0;
	len = 0;
	x = n;
	if (x < 0)
	{
		len++;
		sign = 1;
		x *= -1;
	}
	len += ft_getintlen(x);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (0);
	res = ft_doitoa(x, len, sign, res);
	return (res);
}
