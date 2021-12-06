/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 23:40:27 by rel-fagr          #+#    #+#             */
/*   Updated: 2021/12/06 23:40:30 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *str, ...);
void		ft_putnbr(int n, int *len);
void		ft_putchar(int c, int *len);
void		ft_putstr(char *s, int *len);
void		ft_unsig_(unsigned int n, int *len);
void		ft_hexa(unsigned long int n, int *len, char c);
size_t		ft_strlen(const char *str);

#endif
