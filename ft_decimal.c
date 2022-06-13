/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:24:05 by dcloud            #+#    #+#             */
/*   Updated: 2021/12/10 16:18:23 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decimal(long nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		i = ft_putstr("-2147483648");
		return (i);
	}
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		i += ft_decimal(nb / 10);
		i += ft_decimal(nb % 10);
		return (i);
	}
	else
		i += ft_putchar(nb + '0');
	return (i);
}

int	ft_lowerxdecimal(unsigned long long nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		if (nb >= 10 && nb <= 15)
		{
			i += ft_putchar(nb + 'a' - 10);
			return (i);
		}
		else
		{
			i += ft_lowerxdecimal(nb / 16);
			i += ft_lowerxdecimal(nb % 16);
			return (i);
		}
	}
	else
		i += ft_putchar(nb + '0');
	return (i);
}

int	ft_upperxedecimal(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		if (nb >= 10 && nb <= 15)
		{
			i += ft_putchar(nb + 'A' - 10);
			return (i);
		}
		else
		{
			i += ft_upperxedecimal(nb / 16);
			i += ft_upperxedecimal(nb % 16);
			return (i);
		}
	}
	else
		i += ft_putchar(nb + '0');
	return (i);
}

int	ft_addressdecimal(unsigned long long nb)
{
	int	i;

	i = 0;
	i = ft_putstr("0x");
	i += ft_lowerxdecimal(nb);
	return (i);
}
