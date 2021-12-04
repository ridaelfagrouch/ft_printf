
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

//**********************ft_putnbr**************************

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", len);
	else
	{
		if (n < 10 && n >= 0)
		{
			ft_putchar((n + '0'), len);
		}
		else if (n < 0)
		{
			ft_putchar('-', len);
			ft_putnbr((n * -1), len);
		}
		else if (n >= 10)
		{
			ft_putnbr(n / 10, len);
			ft_putchar(n % 10 + '0', len);
		}
	}
}

//**********************ft_putchar**************************

void	ft_putchar(int c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

//**********************ft_putstr**************************

void	ft_putstr(char *s, int *len)
{
	int	i;
	char tab[] = "(null)";

	if (!s)
		ft_putstr(tab, len);
	else
	{
		i = 0;
		while (s[i])
		{
			ft_putchar(s[i], len);
			i++;
		}
	}
}

//***********************ft_unsigned************************

void	ft_unsig_(unsigned int n, int *len)
{
	if(n >= 0 && n < 10)
		ft_putchar(n + '0', len);
	if(n >= 10)
	{
		ft_unsig_(n / 10, len);
		ft_putchar(n % 10 + '0', len);
	}
}

//***********************ft_hexa***************************

void	ft_hexa(unsigned int n, int *len, char c)
{
	if (n > 15)
	{
		ft_hexa(n / 16, len, c);
		n %= 16;
	}
	if (n >= 10 && n < 16 && c == 'X')
		ft_putchar((n + 55), len);	
	else if (n >= 10 && n < 16 && c == 'x')
		ft_putchar((n + 87), len);
	else
		ft_putchar(n + '0', len);
}

//********************************

void ft_pointer_(unsigned long int n, int *len)
{
	ft_putstr("0x", &*len);
	ft_hexa2(n, &*len);
}
	
void ft_hexa2(unsigned long int n, int *len)
{
	char *base;
	base = "0123456789abcdef";
	if(n > 15)
		ft_hexa2(n / 16, len);
	ft_putchar(base[n % 16], len);
}

//main


// int main()
// {
// 	int len;

// 	len = 0;
// 	 //printf("%llx", 9223372036854775807LL); 
// 	ft_hexa(-11, &len, 'X');
// 	printf("\n%d", len);
// }

