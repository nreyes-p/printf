/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tithan <tithan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:07:13 by nreyes-p          #+#    #+#             */
/*   Updated: 2023/03/19 12:58:26 by tithan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		write(1, &src[i], 1);
		i++;
	}
}

int	ft_printstr(char *src)
{
	int	i;

	i = 0;
	if (!src)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (src[i])
	{
		write(1, &src[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int i)
{
	char	*number;
	int		length;

	length = 0;
	number = ft_itoa(i);
	if (!number)
		return (0);
	length = ft_printstr(number);
	free(number);
	return (length);
}