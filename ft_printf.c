/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tithan <tithan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:07:13 by nreyes-p          #+#    #+#             */
/*   Updated: 2023/03/19 14:22:59 by tithan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_convert(va_list arg, char const formtype)
{
	int	res;

	res = 0;
	if (formtype == 'c')
		res += ft_printchar(va_arg(arg, int));
	else if (formtype == 's')
		res += ft_printstr(va_arg(arg, char *));
	else if (formtype == 'p')
		res += ft_printptr(va_arg(arg, unsigned long long));
	else if (formtype == 'd' || formtype == 'i')
		res += ft_printnbr(va_arg(arg, int));
	else if (formtype == 'u')
		res += ft_printunsigned(va_arg(arg, unsigned int));
	else if (formtype == 'x' || formtype == 'X')
		res += ft_printhex(va_arg(arg, unsigned int), formtype);
	else if (formtype == '%')
		res += ft_printpercent();
	return(res);
}

int	ft_printf(char const *src, ...)
{
	va_list	arg;
	int		i;
	int		res;
	
	i = 0;
	res = 0;
	va_start(arg, src);
	while (src[i])
	{
		if (src[i] == '%')
		{
			res += ft_convert(arg, src[i + 1]);
			i++;
		}
		else
			res += ft_printchar(src[i]);
		i++;
	}
	va_end(arg);
	return (res);
}
