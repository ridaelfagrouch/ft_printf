/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 23:32:04 by rel-fagr          #+#    #+#             */
/*   Updated: 2021/12/06 23:39:20 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_check_str(const char *str, va_list args, int *i, int *len)
{
	(*i)++;
	if (str[*i] == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (str[*i] == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (str[*i] == 'p')
	{
		ft_putstr("0x", len);
		ft_hexa(va_arg(args, unsigned long), len, 'x');
	}
	else if (str[*i] == 'd' || str[*i] == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (str[*i] == 'u')
		ft_unsig_(va_arg(args, unsigned long), len);
	else if (str[*i] == 'x' || str[*i] == 'X')
		ft_hexa(va_arg(args, unsigned int), len, str[*i]);
	else if (str[*i] == '%')
		ft_putchar('%', len);
}

static void	ft_check_sharp(const char *str, int *len, va_list args, int *i)
{
	unsigned int	sharp;

	sharp = 0;
	sharp = va_arg(args, unsigned int);
	(*i)++;
	if (sharp != 0)
	{
		while (str[*i] == '#')
			(*i)++;
		if (str[*i] == 'x')
			ft_putstr("0x", len);
		else if (str[*i] == 'X')
			ft_putstr("0X", len);
		ft_hexa(sharp, len, str[*i]);
	}
	else
		ft_hexa(sharp, len, str[*i]);
}

static void	ft_check_syntax(const char *str, int *i, int *len, va_list args)
{
	int		number;
	char	c[2];

	number = 0;
	(*i)++;
	c[0] = str[*i];
	c[1] = '\0';
	if (str[*i] == '#')
		ft_check_sharp(str, len, args, i);
	else if (str[*i] == c[0] && c[0] != '#')
	{
		(*i)++;
		while (str[*i] == c[0])
			(*i)++;
		if (str[*i] == 'i' || str[*i] == 'd')
		{
			number = va_arg(args, int);
			if (number >= 0)
				ft_putchar(c[0], len);
			ft_putnbr(number, len);
		}
		else if (str[*i] == 's')
			ft_putstr(va_arg(args, char *), len);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '#' || str[i + 1] == '+' || str[i + 1] == ' ')
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
