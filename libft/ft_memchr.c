/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:37:18 by scartage          #+#    #+#             */
/*   Updated: 2022/02/11 20:38:33 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	q;

	i = 0;
	f = (unsigned char *)s;
	q = (unsigned char)c;
	while (i < n)
	{
		if (f[i] == q)
			return (&f[i]);
		i++;
	}
	return (NULL);
}
