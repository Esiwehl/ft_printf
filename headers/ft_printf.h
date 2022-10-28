#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_getlen(size_t num);
char	*base_def(char flag);
char	*ft_itoa(int n);

size_t	ft_putptr(unsigned long long ptr);
size_t  put_hex(size_t n, char format);

size_t	ft_putuint(unsigned int n);
char	*ft_uitoa(unsigned int n);
#endif