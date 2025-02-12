/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 04:34:40 by rben-ais          #+#    #+#             */
/*   Updated: 2024/12/25 04:34:43 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	k;
	char			*p;

	k = 0;
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (len > i - start)
		len = i - start;
	if (start >= i)
		return (ft_strdup(""));
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (s[start] && k < len)
	{
		p[k] = s[start];
		k++;
		start++;
	}
	p[k] = '\0';
	return (p);
}

char	*ft_strchr(const char *str, int ch)
{
	unsigned char	*ptr;
	int				p;

	if (!str)
		return (NULL);
	ptr = (unsigned char *)str;
	p = ft_strlen(str);
	while (p >= 0)
	{
		if (*ptr == (char)ch)
			return ((char *)ptr);
		p--;
		ptr++;
	}
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	k;
	char			*p;

	k = 0;
	i = 0;
	if (!s2)
		return (NULL);
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	while (s1[i])
		p[k++] = (char)s1[i++];
	i = 0;
	while (s2[i])
		p[k++] = (char)s2[i++];
	p[k] = '\0';
	return (p);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		len;

	if (!s)
		return (ft_strdup(""));
	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	while (len--)
		ptr[len] = s[len];
	return (ptr);
}
