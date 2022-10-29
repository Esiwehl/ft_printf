/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 13:55:01 by ewehl         #+#    #+#                 */
/*   Updated: 2022/10/28 13:55:01 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"

size_t	ft_getlen(size_t num, size_t base)
{
	size_t	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / base;
	}
	return (len);
}

char	*base_def(char flag)
{
	char	*base;

	base = NULL;
	if (flag == 'X')
		base = "0123456789ABCDEF";
	else if (flag == 'x')
		base = "0123456789abcdef";
	return (base);
}

size_t	ft_puthex(unsigned long n, char format)
{
	size_t	count;
	size_t	baselen;
	char	*base;

	baselen = 16;
	count = ft_getlen(n, baselen);
	base = base_def(format);
	if (!n)
		return (ft_putstr_len("0"));
	if (n > baselen - 1)
	{
		ft_puthex((n / baselen), format);
		ft_putchar_len(base[n % baselen]);
	}
	else
		ft_putchar_len(base[n]);
	return (count);
}

size_t	ft_putptr(unsigned long ptr)
{
	size_t	count;

	count = 0;
	count += write(1, "0x", 2);
	count += ft_puthex(ptr, 'x');
	return (count);
}
