/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 20:08:20 by ewehl         #+#    #+#                 */
/*   Updated: 2022/10/28 22:08:43 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "headers/ft_printf.h"
#include "headers/ft_printf.h"

static int	get_action(const char *str, va_list ap)
{
	if (*str == 'c')
		return (ft_putchar_len(va_arg(ap, int)));
	else if (*str == 's')
		return (ft_putstr_len(va_arg(ap, char *)));
	else if (*str == 'p')
		return (ft_putptr(va_arg(ap, unsigned long long)));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr_len(va_arg(ap, int)));
	else if (*str == 'u')
		return (ft_putuint(va_arg(ap, unsigned int)));
	else if (*str == 'x')
		return (ft_puthex(va_arg(ap, int), *str));
	else if (*str == 'X')
		return (ft_puthex(va_arg(ap, int), *str));
	else if (*str == '%')
		return (ft_putchar_len('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
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

// int	main(void)
// {
// 	// float x = 7.12134352423;
// 	// char *str = NULL;
// 	// int z =  -2147483648;

// 	unsigned int a = 64250;

// 	int x = ft_printf("M:: %x, %p\n", a, &a);
// 	int y = printf("O:: %x, %p\n", a, &a);

// 	ft_printf("%d\t", x);
// 	ft_printf("%d\n", y);

// 	return (0);
// }
