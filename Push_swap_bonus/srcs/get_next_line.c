/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucifer <lucifer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:21:02 by mrobaii           #+#    #+#             */
/*   Updated: 2022/12/25 17:21:15 by lucifer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <fcntl.h>

int	ft_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_ln(char **str)
{
	char	*tmp;
	char	*line;

	tmp = *str;
	line = ft_substr(*str, 0, ft_index(*str, '\n') + 1);
	*str = ft_strdup(*str + ft_index(*str, '\n') + 1);
	free(tmp);
	return (line);
}

char	*ft_check(char **buff, char **rest)
{
	char	*line;

	if (*rest != NULL && *rest[0] == '\0')
	{
		free(*buff);
		free(*rest);
		return (NULL);
	}
	else if (*rest != NULL)
	{
		free(*buff);
		line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
		return (line);
	}
	free(*buff);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buff;
	int			size;

	if (fd < 0)
		return (NULL);
	if (ft_strchr(rest, '\n'))
		return (get_ln(&rest));
	buff = malloc(sizeof(char) * (1 + 1));
	size = read(fd, buff, 1);
	while (size > 0)
	{
		buff[size] = '\0';
		rest = ft_strjoin(rest, buff);
		if (ft_strchr(rest, '\n'))
		{
			free(buff);
			return (get_ln(&rest));
		}
		size = read(fd, buff, 1);
	}
	if (size == 0)
		return (ft_check(&buff, &rest));
	free(buff);
	return (NULL);
}
