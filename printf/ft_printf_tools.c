/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:54:10 by scartage          #+#    #+#             */
/*   Updated: 2022/03/11 19:21:26 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int	counter;

	counter = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i] != '\0')
	{
		counter = counter + ft_putchar(s[i]);
		i++;
	}
	return (counter);
}

int	ft_putnbr(int n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		if (n == INT_MIN)
			counter = counter + ft_putstr("-2147483647");
		else
		{
			counter = counter + ft_putchar('-');
			n = -n;
		}
	}
	if (n >= 0)
	{
		if (n / 10 > 0)
			counter = counter + ft_putnbr(n / 10);
		counter = counter + ft_putchar((n % 10 + '0'));
	}
	return (counter);
}

int	ft_putnbr_uns(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n >= 0)
	{
		if (n / 10 > 0)
			counter += ft_putnbr_uns(n / 10);
		counter += ft_putchar(n % 10 + '0');
	}
	return (counter);
}
