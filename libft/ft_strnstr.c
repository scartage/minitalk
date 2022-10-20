/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:24:37 by scartage          #+#    #+#             */
/*   Updated: 2022/02/01 18:53:14 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*h;

	i = 0;
	h = (char *)haystack;
	if (ft_strlen(needle) == 0)
		return (h);
	if (ft_strlen(h) == 0)
		return (0);
	while ((ft_strlen(needle) + i) <= len)
	{
		if (ft_strncmp(&h[i], needle, ft_strlen(needle)) == 0)
			return (&h[i]);
		i++;
	}
	return (0);
}
