/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:43:43 by scartage          #+#    #+#             */
/*   Updated: 2022/03/04 12:31:25 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include	<unistd.h>
# include	<stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char	*str);
int	ft_putnbr(int n);
int	ft_putnbr_uns(unsigned int n);
int	ft_putp(unsigned long long n);
int	ft_put_ptr(unsigned long long n);
int	ft_putnbr_hex_min(va_list args);
int	ft_putnbr_hex_may(va_list args);
int	ft_putnbr_hex(unsigned int n, char base);
int	ft_print_args(const char *s, va_list va_arg);
int	ft_printf(const char *str, ...);

#endif
