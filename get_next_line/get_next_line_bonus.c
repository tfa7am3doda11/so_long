/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 04:34:27 by rben-ais          #+#    #+#             */
/*   Updated: 2024/12/25 04:34:29 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_count(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

static char	*ft_get_line(char *str)
{
	char	*ptr;
	int		i;
	int		k;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	k = ft_count(str);
	ptr = malloc(k + 1);
	if (!ptr)
		return (NULL);
	while (i < k)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*ft_read(int fd, char *str)
{
	char	*buf;
	char	*tmp;
	int		len;

	if (!str)
		str = ft_strdup("");
	if (!str)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(str), NULL);
	len = 1;
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = '\0';
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
		if (!str || ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*line;
	char		*tmp;

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(str[fd]), str[fd] = NULL, NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd] || str[fd][0] == '\0')
		return (free(str[fd]), str[fd] = NULL, NULL);
	line = ft_get_line(str[fd]);
	if (!line)
		return (free(str[fd]), str[fd] = NULL, NULL);
	tmp = ft_substr(str[fd], ft_count(str[fd]), ft_strlen(str[fd])
			- ft_count(str[fd]));
	free(str[fd]);
	str[fd] = tmp;
	return (line);
}
