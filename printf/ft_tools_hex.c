/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:31:38 by scartage          #+#    #+#             */
/*   Updated: 2022/03/10 19:25:54 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n, char base)
{
	int	counter;

	counter = 0;
	if (n >= 16)
	{	
		counter += ft_putnbr_hex(n / 16, base);
		counter += ft_putnbr_hex(n % 16, base);
	}
	else
	{
		if (n < 10)
			counter += ft_putchar(n + '0');
		else
			counter += ft_putchar(n - 10 + base);
	}
	return (counter);
}

int	ft_putnbr_hex_min(va_list args)
{
	unsigned long	aux;

	aux = va_arg(args, unsigned int);
	if (aux == 0)
		return (ft_putchar('0'));
	return (ft_putnbr_hex(aux, 'a'));
}

int	ft_putnbr_hex_may(va_list args)
{
	unsigned long	aux;

	aux = va_arg(args, unsigned int);
	if (aux == 0)
		return (ft_putchar('0'));
	return (ft_putnbr_hex(aux, 'A'));
}
