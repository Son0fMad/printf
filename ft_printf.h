/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:44:53 by dcloud            #+#    #+#             */
/*   Updated: 2021/12/10 16:18:31 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printf(const char *stroka, ...);
int	ft_decimal(long nb);
int	ft_lowerxdecimal(unsigned long long nb);
int	ft_upperxedecimal(unsigned int nb);
int	ft_addressdecimal(unsigned long long nb);

#endif
