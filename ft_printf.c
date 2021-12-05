//  ███████╗████████╗     ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗
//  ██╔════╝╚══██╔══╝     ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝
//  █████╗     ██║        ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  
//  ██╔══╝     ██║        ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝  
//  ██║        ██║███████╗██║     ██║  ██║██║██║ ╚████║   ██║   ██║     
//  ╚═╝        ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝     

#include "ft_printf.h"
#include <stdio.h>

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
			ft_check_str(str, args, &i, &len);
		else
			ft_putchar(str[i], &len);
		i++;
	}
	return (len);
}