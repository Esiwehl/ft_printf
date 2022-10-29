/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 13:54:49 by ewehl         #+#    #+#                 */
/*   Updated: 2022/10/29 17:24:08 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/libft.h"

size_t	ft_putchar_len(int c)
{
	return (write(1, &c, 1));
}

size_t	ft_putstr_len(char *str)
{
	size_t	idx;

	idx = 0;
	if (!str)
		return (ft_putstr_len("(null)"));
	while (str[idx])
		write(1, &str[idx++], 1);
	return (idx);
}

size_t	ft_putnbr_len(int n)
{
	size_t	count;
	char	*num;

	num = ft_itoa(n);
	count = ft_putstr_len(num);
	free(num);
	return (count);
}
