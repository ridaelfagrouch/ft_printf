//  ███████╗████████╗     ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗
//  ██╔════╝╚══██╔══╝     ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝
//  █████╗     ██║        ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  
//  ██╔══╝     ██║        ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝  
//  ██║        ██║███████╗██║     ██║  ██║██║██║ ╚████║   ██║   ██║     
//  ╚═╝        ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝     

#include "ft_printf_bonus.h"
#include <stdio.h>

// typedef struct form
// {
// 	char	fla;
// 	int		number;
// 	char	*para;
// 	int		width;
// 	char	*preci;

// } form;


static void	ft_check_str(const char *str, va_list args, int *i, int *len)
{
	(*i)++;
	if(str[*i] == 'c')
		ft_putchar(va_arg(args, int), len);
	else if(str[*i] == 's')
		ft_putstr(va_arg(args, char *), len);
	else if(str[*i] == 'p')
	{
		ft_putstr("0x", len);
		ft_hexa(va_arg(args, unsigned long), len, 'x');
	}
	else if(str[*i] == 'd' || str[*i] == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if(str[*i] == 'u')
	    ft_unsig_(va_arg(args, unsigned long), len);
	else if(str[*i] == 'x' || str[*i] == 'X')
	    ft_hexa(va_arg(args, unsigned int), len, str[*i]);
	else if(str[*i] == '%')
	    ft_putchar('%', len);
}

static void	ft_check_flags(char check, int *len, int *i, const char *str, va_list args)
{
	
	if(check == '#')
	{
		(*i)++;
		while(str[*i] == '#')
			(*i)++;
		if(str[*i] == 'x')
			ft_putstr("0x", len);
		else if (str[*i] == 'X')
			ft_putstr("0X", len);
		ft_hexa(va_arg(args, unsigned int), len, str[*i]);
	}
	else if(check == ' ')
	{
		(*i)++;
		while(str[*i] == ' ')
			(*i)++;
		ft_putchar(' ', len);
		if(str[*i] == 'i' || str[*i] == 'd')
			ft_check_str(str, args, i--, len);
	}
	else if(check == '+')
		ft_putchar('+', len);
}


static void ft_check_syntax(const char *str, int *i, int *len, va_list args)
{
	int number;

	
	number = 0;
	(*i)++;
	if(str[*i] == '#')
		ft_check_flags('#', len, i, str, args);
	else if(str[*i] == ' ')
		ft_check_flags(' ', len, i, str, args);
	else if(str[*i] == '+')
	{
		(*i)++;
		while(str[*i] == '+')
			(*i)++;
		if(str[*i] == 'd' || str[*i] == 'i')
			number = va_arg(args, int);
		if(number > 0)
			ft_check_flags('+', len, i, str, args);
		ft_putnbr(number, len);
	}
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int i;
	int len; 

	va_start(args, str);
	i = 0;
	len = 0;
	while(str[i])
	{
		if(str[i] == '%')
		{
			if(str[i + 1] == '#' || str[i + 1] == '+' || str[i + 1] == ' ')
				ft_check_syntax(str, &i, &len, args);
			else
				ft_check_str(str, args, &i, &len);
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	return (len);
}


// #include <limits.h>
int main()
{
	// int len;

	// len = 0;
	//  printf("%llx", 9223372036854775807LL); 
	// ft_hexa(-1, &len, 'X');
	// ft_printf("%d\n",ft_printf("%x", -9));
	//ft_printf("%p", LONG_MAX);
	ft_printf("%d--", printf(" %d ", -99));
	//ft_printf("%d--", ft_printf(" %#X ", -99));
}

