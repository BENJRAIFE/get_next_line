/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenjrai <bouchrabenjraife07@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:44:04 by bbenjrai          #+#    #+#             */
/*   Updated: 2023/12/13 19:55:03 by bbenjrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;
	char	*s2;

	s2 = (char *)s1;
	i = 0;
	str = malloc(sizeof(char) * ft_strlen(s2) + 1);
	if (str == 0)
		return (0);
	while (s2[i])
	{
		str[i] = s2[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;
	int		len;
	int		j;

	j = 0;
	i = 0;
	if (!s1 && s2)
	{
		s1 = ft_strdup("");
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}
