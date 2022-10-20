/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:20:41 by scartage          #+#    #+#             */
/*   Updated: 2022/01/29 18:28:47 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*g;
	size_t	len;

	len = ft_strlen(s1) + 1;
	g = malloc(len);
	if (g == NULL)
		return (NULL);
	ft_memcpy(g, s1, len);
	return (g);
}
