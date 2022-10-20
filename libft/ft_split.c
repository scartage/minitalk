/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:33:21 by scartage          #+#    #+#             */
/*   Updated: 2022/03/22 20:21:24 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counting_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_making_words(char const *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = ft_calloc(sizeof(char), i + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	strn;
	size_t	i;
	char	**string;

	strn = ft_counting_words(s, c);
	string = ft_calloc(sizeof(char **), strn + 1);
	if (string == NULL)
		return (NULL);
	i = 0;
	while (i < strn)
	{
		while (*s == c)
			s++;
		string[i] = ft_making_words(s, c);
		if (string[i] == NULL)
		{
			while (i > 0)
				free(string[--i]);
			free(string);
			return (0);
		}
		s += ft_strlen(string[i++]);
	}
	string[i] = 0;
	return (string);
}
