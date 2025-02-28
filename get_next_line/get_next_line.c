/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 04:34:53 by rben-ais          #+#    #+#             */
/*   Updated: 2025/02/27 16:37:24 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	if (!str || str[0] == '\0')
		return (NULL);
	ptr = malloc(ft_count(str) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ptr[i++] = '\n';
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
	static char	*str;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(str), str = NULL, NULL);
	str = ft_read(fd, str);
	if (!str || str[0] == '\0')
		return (free(str), str = NULL, NULL);
	line = ft_get_line(str);
	if (!line)
		return (free(str), str = NULL, NULL);
	tmp = ft_substr(str, ft_count(str), ft_strlen(str) - ft_count(str));
	free(str);
	str = tmp;
	return (line);
}
