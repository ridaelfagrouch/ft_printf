#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
#include <unistd.h>

int     ft_printf(const char *str, ...);
void	ft_putnbr(int n, int *len);
void	ft_putchar(int c, int *len);
void    ft_putstr(char *s, int *len);
// void	ft_pointer(void *p, int *len);
void	ft_unsig_(long n, int *len);
void	ft_hexa(long long n, int *len, char c);

#endif