/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tithan <tithan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:07:13 by nreyes-p          #+#    #+#             */
/*   Updated: 2023/03/19 15:29:39 by tithan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlength(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_putptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	res;

	res = 0;
	res += write(1, "0x", 2);
	if (ptr == 0)
		res += write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		res += ft_ptrlength(ptr);
	}
	return (res);
}

int	ft_printunsigned(unsigned int i)
{
	char	*number;
	int		length;

	length = 0;
	number = ft_unsigned_itoa(i);
	if (!number)
		return (0);
	length = ft_printstr(number);
	free(number);
	return (length);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char		*res;
	int			len;

	len = 0;
	len += ft_getuintlen(n);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (0);
	res[len] = 0;
	while (len > 0)
	{
		res[--len] = (n % 10) + 48;
		n /= 10;
	}
	return (res);
}

int	ft_getuintlen(unsigned int n)
{
	int	i;

	i = 1;
	if (n < 10)
		return (i);
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_printhex(unsigned int n, const char c)
{
	int	length;

	length = 0;
	if (n == 0)
		return (write(1, "0", 1));
	length = ft_hex_length(n);
	ft_puthex(n, c);
	return (length);
}

void	ft_puthex(unsigned int n, const char c)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, c);
		ft_puthex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + (c - 23)), 1);
	}
}

int	ft_hex_length(unsigned int n)
{
	int	i;

	i = 1;
	if (n < 16)
		return (i);
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int ft_printpercent()
{
	return (write(1, "%", 1));
}