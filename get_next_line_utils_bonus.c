/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:44:03 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/23 18:23:14 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t		ft_strlen(char const *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char				*ft_strchr(const char *str, int c)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}

static void			*ft_calloc(size_t num, size_t size)
{
	void	*res;
	char	*str;
	size_t	i;

	res = malloc(num * size);
	if (!res)
		return (0);
	i = 0;
	str = (char *)res;
	while (i < (num * size))
		str[i++] = '\0';
	return (res);
}

char				*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*dest;

	if (!src)
		return (0);
	len = ft_strlen(src) + 1;
	dest = (char *)ft_calloc(len, sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char				*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!(res = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char))))
		return (0);
	while (s1[j])
		res[i++] = s1[j++];
	free(s1);
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	return (res);
}
