/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:11:49 by scartage          #+#    #+#             */
/*   Updated: 2022/01/24 17:44:24 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{		
	size_t	d;
	size_t	s;

	d = ft_strlen(dst);
	s = 0;
	while (*dst != '\0')
		dst++;
	if (dstsize > d)
	{
		s = ft_strlcpy(dst, src, (dstsize - d));
		return (d + s);
	}
	return (dstsize + ft_strlen((char *)src));
}
