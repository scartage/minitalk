/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:40:18 by scartage          #+#    #+#             */
/*   Updated: 2022/02/07 18:33:02 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*k;
	char			*f;
	unsigned char	q;

	i = 0;
	k = 0;
	f = (char *)s;
	q = (unsigned char)c;
	if (q == 0)
		return (f + ft_strlen(f));
	while (f[i] != '\0')
	{
		if (f[i] == q)
			k = &f[i];
		i++;
	}
	if (k != 0)
		return (k);
	else
		return (NULL);
}
