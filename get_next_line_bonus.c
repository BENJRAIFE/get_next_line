/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenjrai <bouchrabenjraife07@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:41:32 by bbenjrai          #+#    #+#             */
/*   Updated: 2023/12/16 21:15:32 by bbenjrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	*ft_free(char *buf)
{
	free(buf);
	return (NULL);
}

static char	*get_second_line_bonus(char *buffer)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (!buffer[i])
		return (ft_free(buffer));
	str = (char *)malloc(ft_strlen(buffer) - i + 1);
	if (!str)
		return (ft_free(buffer));
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

static char	*get_line_bonus(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*get_str_bonus(int fd, char *buffer)
{
	ssize_t	bytes_offs;
	char	*str;

	bytes_offs = 1;
	str = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		bytes_offs = read(fd, str, BUFFER_SIZE);
		if (bytes_offs <= 0)
			break ;
		str[bytes_offs] = '\0';
		buffer = ft_strjoin(buffer, str);
	}
	free(str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[256];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = get_str_bonus(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line_bonus(buffer[fd]);
	buffer[fd] = get_second_line_bonus(buffer[fd]);
	return (line);
}
