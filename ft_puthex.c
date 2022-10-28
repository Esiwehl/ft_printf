// #include "ft_printf.h"
// #include "libft.h"
#include <stdlib.h>

size_t	ft_getlen(size_t num)
{
	size_t	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

char	*base_def(char flag)
{
	char *base;

	if (flag == 'X')
		base = "0123456789ABCDEF";
	else if (flag == 'x')
		base = "0123456789abcdef";
	return (base);
}

size_t	ft_putptr(unsigned long long ptr)
{
	size_t count;

	count = 0;
	count += write(1, "0x", 2);
	if (ptr == 0)
		count += write(1, "0", 1);
	else
		count += ft_puthex(ptr, 'x');
	return (count);
}