/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:32:10 by scartage          #+#    #+#             */
/*   Updated: 2022/03/10 15:12:52 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*g;
	size_t	size;

	size = ft_strlen(s);
	if (start > size)
		start = size;
	if (len > size - start)
		len = size - start;
	g = (char *)malloc(sizeof(char) * (len + 1));
	if (g == NULL)
		return (NULL);
	ft_memmove(g, &s[start], len);
	g[len] = '\0';
	return (g);
}
