/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:44:54 by scartage          #+#    #+#             */
/*   Updated: 2022/02/22 17:14:44 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		counter;
	va_list	args;

	counter = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (*(str + 1) == '%')
				counter = counter + ft_putchar('%');
			else
				counter = counter + ft_print_args(str, args);
			str = str + 1;
		}
		else
			counter = counter + ft_putchar(*str);
			str++;
	}
	va_end(args);
	return (counter);
}
