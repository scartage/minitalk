/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:41:59 by scartage          #+#    #+#             */
/*   Updated: 2022/02/22 17:13:36 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_args(const char *str, va_list args)
{
	if (*(str + 1) == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*(str + 1) == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*(str + 1) == 'p')
		return (ft_putp(va_arg(args, unsigned long long)));
	else if (*(str + 1) == 'd' || *(str + 1) == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*(str + 1) == 'u')
		return (ft_putnbr_uns(va_arg(args, unsigned int)));
	else if (*(str + 1) == 'x')
		return (ft_putnbr_hex_min(args));
	else if (*(str + 1) == 'X')
		return (ft_putnbr_hex_may(args));
	else
		return (ft_putchar(*(str + 1)));
	return (0);
}
