/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:47:56 by scartage          #+#    #+#             */
/*   Updated: 2022/02/22 17:15:39 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(unsigned long long n)
{
	int	counter;

	counter = 0;
	if (n >= 16)
	{
		counter += ft_put_ptr(n / 16);
		counter += ft_put_ptr(n % 16);
	}
	else
	{
		if (n < 10)
			counter += ft_putchar(n + '0');
		else
			counter += ft_putchar(n - 10 + 'a');
	}
	return (counter);
}

int	ft_putp(unsigned long long n)
{
	int	counter;

	counter = 2;
	write(1, "0x", counter);
	return (counter + ft_put_ptr(n));
}
