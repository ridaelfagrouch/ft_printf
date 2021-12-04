#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
#include <unistd.h>

int     ft_printf(const char *str, ...);
void	ft_putnbr(int n, int *len);
void	ft_putchar(int c, int *len);
void    ft_putstr(char *s, int *len);
void	ft_unsig_(unsigned int n, int *len);
void	ft_hexa(unsigned int n, int *len, char c);
void    ft_pointer_(unsigned long int n, int *len);
void    ft_hexa2(unsigned long int n, int *len);
static void	ft_check_str(const char *str, va_list args);

#endif