#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>


int             ft_printf(const char *str, ...);
int             ft_putnbr(int n, int *len);
char            ft_putchar(int c, int *len);
char            *ft_putstr(char *s, int *len);
unsigned int    ft_unsig_(unsigned int n, int *len);
void	        ft_hexa(unsigned long int n, int *len, char c);

#endif