/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:14:10 by scartage          #+#    #+#             */
/*   Updated: 2022/02/11 18:43:59 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_wrt(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
			write (fd, "-2147483648", 11);
		else
		{
			ft_wrt('-', fd);
			n = -n;
		}
	}
	if (n >= 0)
	{	
		if (n / 10 > 0)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_wrt((n % 10 + '0'), fd);
	}
}
