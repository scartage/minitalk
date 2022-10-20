/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:33:50 by scartage          #+#    #+#             */
/*   Updated: 2022/02/07 19:26:03 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		len;
	int		i;

	len = ft_strlen(s);
	i = 0;
	if (s != NULL || f != NULL)
	{
		while (i < len)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
