//  ███████╗████████╗     ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗
//  ██╔════╝╚══██╔══╝     ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝
//  █████╗     ██║        ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  
//  ██╔══╝     ██║        ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝  
//  ██║        ██║███████╗██║     ██║  ██║██║██║ ╚████║   ██║   ██║     
//  ╚═╝        ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝     

#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *str, ...)
{
	va_list args;
	int i;
	int len;

	i = 0;
	len = 0;
	va_start(args, str);
	while(str[i])
	{
		if(str[i] == '%')
		{
			i++;
			if(str[i] == 'c')
				ft_putchar(va_arg(args, int), &len);
			else if(str[i] == 's')
				ft_putstr(va_arg(args, char *), &len);
			// else if(str[i] == 'p')
			//     ft_pointer(va_arg(args, void *), &len);
			else if(str[i] == 'd' || str[i] == 'i')
				ft_putnbr(va_arg(args, int), &len);
			else if(str[i] == 'u')
			    ft_unsig_(va_arg(args, unsigned), &len);
			else if(str[i] == 'x' || str[i] == 'X')
			    ft_hexa(va_arg(args, unsigned), &len, str[i]);
			else if(str[i] == '%')
			    ft_putchar('%', &len);
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	return (len);
}

// int main()
// {
// 	int len;

// 	len = 0;
// 	 //printf("%llx", 9223372036854775807LL); 
// 	// ft_hexa(-1, &len, 'X');
// 	ft_printf("%d\n",ft_printf("%x", -9));
// }

