//  ███████╗████████╗     ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗
//  ██╔════╝╚══██╔══╝     ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝
//  █████╗     ██║        ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  
//  ██╔══╝     ██║        ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝  
//  ██║        ██║███████╗██║     ██║  ██║██║██║ ╚████║   ██║   ██║     
//  ╚═╝        ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝     

#include "ft_printf.h"
#include <stdio.h>

static void	ft_check_str(const char *str, va_list args)
{
	int len = 0;
	if(str[1] == '%')
	{
		if(str[1] == 'c')
			ft_putchar(va_arg(args, int), &len);
		else if(str[1] == 's')
			ft_putstr(va_arg(args, char *), &len);
		else if(str[1] == 'p')
			ft_pointer_(va_arg(args, unsigned long int), &len);
		else if(str[1] == 'd' || str[1] == 'i')
			ft_putnbr(va_arg(args, int), &len);
		else if(str[1] == 'u')
		    ft_unsig_(va_arg(args, unsigned int), &len);
		else if(str[1] == 'x' || str[1] == 'X')
		    ft_hexa(va_arg(args, unsigned int), &len, str[1]);
		else if(str[1] == '%')
		    ft_putchar('%', &len);
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
		if(str[i++] == '%')
			ft_check_str(str, args);
		else
			ft_putchar(str[i], &len);
		i++;
	}
	return (len);
}


// #include <limits.h>
// int main()
// {
// 	// int len;

// 	// len = 0;
// 	//  printf("%llx", 9223372036854775807LL); 
// 	// ft_hexa(-1, &len, 'X');
// 	// ft_printf("%d\n",ft_printf("%x", -9));
// 	ft_printf("%p", LONG_MAX);
// 	printf("\n%p", LONG_MAX);
// }

