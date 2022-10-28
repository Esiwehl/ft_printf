/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 20:08:20 by ewehl         #+#    #+#                 */
/*   Updated: 2022/10/27 21:26:50 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

size_t	ft_putchar_len(int c)
{
	return(write(1, &c, 1));
}

size_t	ft_putstr_len(char *str)
{
	size_t idx;

	idx = 0;
	if (str[idx] == NULL)
		str = "(null)";
	while(str[idx])
		write(1, &str[idx++], 1);
	return (idx); 
}

size_t	ft_putnbr_len(int n)
{
	size_t	count;
	char	*num;

	count = 0;
	num = ft_itoa(n);
	len = ft_putstr_len(num);
	free(num);
	return (count);
}

size_t put_hex(size_t n, char format)
{
	size_t	count;
	size_t	baselen;
	char	*base;

	count = ft_getlen(n);
	base = base_def(format);
	baselen = ft_strlen(base);
	if (n > baselen - 1)
	{
		put_hex((n / baselen), format);
		ft_putchar_len(base[n % baselen]);
	}
	else
		ft_putchar_len(base[n]);
	ft_printf("count = %d\n", count);
	return (count);
}

static int get_action(const char *str, va_list ap)
{
	if (*str == 'c')
		return(ft_putchar_len(va_arg(ap, int)));
	else if (*str == 's')
		return(ft_putstr_len(va_arg(ap, char *)));
	else if (*str == 'p')
		return ();
	else if (*str == 'd' || *str == 'i')
		return(put_nbr_len(va_arg(ap, int)));
	else if (*str == 'u')
		puts("Is an uint");
	else if (*str == 'x')
		return(put_hex(va_arg(ap, int), *str));
	else if (*str == 'X')
		return(put_hex(va_arg(ap, int), *str));
	else if (*str == '%')
		return(ft_putchar_len('%'));
	return (0);
}

int ft_printf(const char *format, ...)
{
	int			idx;
	size_t		count;
	va_list		args;
	
	idx = 0;
	count = 0;
	va_start(args, format);
	while (format[idx])
	{
		if (format[idx] != '%')
			count += ft_putchar_len(format[idx]);
		if (format[idx] == '%')
			count += get_action(&format[++idx], args);
		idx++;
	}
	va_end(args);
	return (count);
}

int main()
{
	// float x = 7.12134352423;
	// int y = 0xFA;
	int z =  -2147483648;

	// unsigned int a = 64250;

	int x = ft_printf("%X, %d\n", z, z);
	int y = printf("%X, %d\n", z, z);

	ft_printf("%d\t", x);
	ft_printf("%d\n", y);

	return (0);
}
