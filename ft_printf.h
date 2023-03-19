/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tithan <tithan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:05:18 by nreyes-p          #+#    #+#             */
/*   Updated: 2023/03/19 14:25:59 by tithan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int	ft_printf(char const *src, ...);
int	ft_convert(va_list arg, char const formtype);
int	ft_printchar(int c);
void	ft_putstr(char *src);
int	ft_printstr(char *src);
int	ft_printptr(unsigned long long ptr);
void	ft_putptr(unsigned long long num);
int	ft_ptrlength(unsigned long long num);
int	ft_printnbr(int i);
int	ft_printunsigned(unsigned int i);
char	*ft_unsigned_itoa(unsigned int n);
int	ft_getuintlen(unsigned int n);
int	ft_printhex(unsigned int n, char c);
void	ft_puthex(unsigned int n, const char c);
int	ft_hex_length(unsigned int n);
int ft_printpercent(void);

#endif
