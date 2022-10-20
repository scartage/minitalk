/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:35:42 by scartage          #+#    #+#             */
/*   Updated: 2022/03/09 14:19:47 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while (d[i] && s[i] && i < n)
	{
		if (d[i] != s[i])
			return (d[i] - s[i]);
		i++;
	}
	if (i < n)
		return (d[i] - s[i]);
	return (0);
}
