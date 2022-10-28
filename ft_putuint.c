#include "ft_printf.h"

char	*ft_uitoa(unsigned int n)
{
	char		*numa;
	size_t		len;

	len = ft_getlen(n);
	numa = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	numa[len] = '\0';
	if (n == 0)
		numa[0] = '0';
	while (len-- > 0 && n)
	{
		numa[len] = (n % 10) + '0';
		n /= 10;
	}
	return (numa);
}

size_t	ft_putuint(unsigned int n)
{
	size_t	count;
	char	*num;

	count = 0;
		num = ft_uitoa(n);
		count += ft_putstr(num);
		free(num);
	return (count);
}
