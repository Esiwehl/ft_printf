#include "ft_printf.h"
// #include "libft.h"

size_t	ft_getlen(*void num)
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

char	*ft_itoa(int n)
{
	char	*numa;
	size_t		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_getlen(n);
	numa = (char *)malloc(sizeof(char) * (len + 1));
	if (!numa)
		return (NULL);
	numa[len] = '\0';
	if (n < 0)
	{
		n = -n;
		numa[0] = '-';
	}
	if (n == 0)
		numa[0] = '0';
	while (len-- > 0 && n)
	{
		numa[len] = (n % 10) + '0';
		n /= 10;
	}
	return (numa);
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
	count += ft_puthex(ptr, 'x');
	return (count);
}