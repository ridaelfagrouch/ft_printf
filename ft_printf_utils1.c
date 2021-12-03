
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

//**********************ft_putnbr**************************

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", &*len);
	else
	{
		if (n < 10 && n >= 0)
		{
			ft_putchar((n + '0'), &*len);
		}
		else if (n < 0)
		{
			ft_putchar('-', &*len);
			ft_putnbr((n * -1), &*len);
		}
		else if (n >= 10)
		{
			ft_putnbr(n / 10, &*len);
			ft_putchar(n % 10 + '0', &*len);
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
		ft_putstr(tab, &*len);
	else
	{
		i = 0;
		while (s[i])
		{
			ft_putchar(s[i], &*len);
			i++;
		}
	}
}

//***********************ft_unsigned************************

void	ft_unsig_(long n, int *len)
{
	unsigned int p;

	p = (unsigned int) n;
	if(p >= 0 && p < 10)
		ft_putchar(p + '0', &*len);
	if(p >= 10)
	{
		ft_unsig_(p / 10, &*len);
		ft_putchar(p % 10 + '0', &*len);
	}
}

//***********************ft_hexa***************************

void	ft_hexa(long long n, int *len, char c)
{
	if (n < 10 && n >= 0)
		ft_putchar(n + '0', &*len);
	else if (n < 0)
		{
			ft_putchar('-', &*len);
			ft_hexa((n * -1), &*len, c);
		}
	else if (n >= 10 && n < 16 && c == 'X')
		ft_putchar((n + 55), &*len);	
	else if (n >= 10 && n < 16 && c == 'x')
		ft_putchar((n + 87), &*len);
	else if (n > 15)
	{
		ft_hexa(n / 16, &*len, c);
		ft_putchar(n % 16 + '0', &*len);
	}
}

//***********************ft_pointer************************

// void	ft_pointer(void *p, int *len)
// {
// 	write(1, &p, 10);
// 	(*len)++;
// }

// int main()
// {
// 	int len;

// 	len = 0;
// 	 //printf("%llx", 9223372036854775807LL); 
// 	ft_hexa(-1, &len, 'X');
// 	printf("\n%d", len);
// }

