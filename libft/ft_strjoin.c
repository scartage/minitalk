/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:23:24 by scartage          #+#    #+#             */
/*   Updated: 2022/02/06 16:37:21 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*g;

	g = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (g == NULL)
		return (NULL);
	ft_strlcpy(g, s1, ft_strlen(s1) + 1);
	ft_strlcat(g, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (g);
}
