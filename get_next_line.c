/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:08:27 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/23 18:20:51 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_gnl_buf(char **str, char **line, char *tmp)
{
	char *temp;

	*tmp++ = '\0';
	*line = ft_strdup(*str);
	if (*tmp == '\0')
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	temp = ft_strdup(tmp);
	free(*str);
	*str = temp;
	return (1);
}

static int			ft_gnl_tail(char **str, char **line)
{
	char *tmp;

	if (*str)
	{
		if ((tmp = ft_strchr(*str, 10)))
			return (ft_gnl_buf(str, line, tmp));
		*line = *str;
		*str = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static char	*str[MAX_OPEN_FILES];
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];
	int			readed_bytes;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((read(fd, buf, 0)) < 0)
		return (-1);
	while ((readed_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[readed_bytes] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
		if ((tmp = ft_strchr(str[fd], 10)))
			return (ft_gnl_buf(&str[fd], line, tmp));
	}
	if (readed_bytes < 0)
		return (-1);
	return (ft_gnl_tail(&str[fd], line));
}
