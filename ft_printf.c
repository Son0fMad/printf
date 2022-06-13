/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:44:29 by dcloud            #+#    #+#             */
/*   Updated: 2021/12/10 16:18:36 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (NULL);
}

int	check_simbol(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_addressdecimal(va_arg(ap, unsigned long long)));
	if (c == 'd' || c == 'i')
		return (ft_decimal(va_arg(ap, int)));
	if (c == 'u')
		return (ft_decimal(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_lowerxdecimal(va_arg(ap, unsigned int)));
	if (c == 'X')
		return (ft_upperxedecimal(va_arg(ap, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *stroka, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, stroka);
	while (stroka[i])
	{
		if (stroka[i] == '%' && ft_strchr("cspdiuxX%", stroka[i + 1]))
		{
			count = count + check_simbol(stroka[++i], ap);
			i++;
		}
		else
		{
			count = count + ft_putchar(stroka[i]);
			i++;
		}
	}
	va_end (ap);
	return (count);
}
