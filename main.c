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

int ft_printf(const char *format, ...);

size_t	ft_putchar_len(int c)
{
	return(write(1, &c, 1));
}

size_t	ft_putstr_len(char *str)
{
	size_t count;

	count = 0;
	while(*str)
		count += ft_putchar_len(*(str++));
	return (count); 
}

size_t	ft_strlen(char *str)
{
	size_t idx;

	idx = 0;
	while (str[idx])
		idx++;
	return(idx);
}

char	*base_def(int flag)
{
	char *base;

	if (flag == 1)
		base = "0123456789ABCDEF";
	else if (flag == 2)
		base = "0123456789abcdef";
	else
		base = "0123456789";
	return (base);
}

size_t	put_nbr(int n, int flag)
{
	size_t	count;
	char	*base;

	count = 0;
	base = base_def(flag);
	if (n == -2147483648)
	{
		put_nbr((n / 10), flag);
		count += ft_putchar_len((8 + '0'));
	}
	else if (n < 0)
	{
		count += ft_putchar_len('-');
		count += put_nbr(-n, flag);
	}
	else if (n > 9)
	{
		put_nbr((n / 10), flag);
		count += ft_putchar_len(base[n % 10]);
	}
	else
		count += ft_putchar_len(base[n]);
	return (count);
}

size_t put_hex(int n, int flag)
{
	size_t	count;
	size_t	baselen;
	char	*base;

	count = 0;
	base = base_def(flag);
	baselen = ft_strlen(base);
	if (n < 0)
		put_hex(-n, flag);
	if (n > (int) baselen - 1)
	{
		put_hex((n / baselen), flag);
		count += ft_putchar_len(base[n % baselen]);
	}
	else
		count += ft_putchar_len(base[n]);
	return (count);
}

static int get_action(const char *str, va_list ap)
{
	if (*str == 'c')
		return(ft_putchar_len(va_arg(ap, int)));
	else if (*str == 's')
		return(ft_putstr_len(va_arg(ap, char *)));
	else if (*str == 'p')
		puts("Is an Address");
	else if (*str == 'd' || *str == 'i')
		return(put_nbr(va_arg(ap, int), 0));
	else if (*str == 'u')
		puts("Is an uint");
	else if (*str == 'x')
		return(put_hex(va_arg(ap, int), 2));
	else if (*str == 'X')
		return(put_hex(va_arg(ap, int), 1));
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
	int z =  -2147483647;

	// unsigned int a = 64250;

	ft_printf("%X, %d\n", z, z);
	printf("%X, %d\n", z, z);

	return (0);
}
