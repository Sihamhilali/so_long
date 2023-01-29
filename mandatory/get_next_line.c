/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:06:56 by selhilal          #+#    #+#             */
/*   Updated: 2023/01/28 16:11:48 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

BUFFER_SIZE = 1;

char	*ft_write(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 2));
	if (!ptr)
		return (0);
	i = -1;
	while (str[++i] && str[i] != '\n')
		ptr[i] = str[i];
	if (str[i] == '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*save(char *str)
{
	int		i;
	char	*ptr;
	int		c;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str + i) + 1));
	if (!ptr)
		return (NULL);
	i++;
	c = 0;
	while (str[i])
		ptr[c++] = str[i++];
	ptr[c] = '\0';
	free(str);
	return (ptr);
}

char	*ft_read(int fd, char *static_buffer)
{
	char	*buffer;
	int		size;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size = 1;
	while (!ft_strchr(static_buffer, '\n') && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		static_buffer = ft_strjoin(static_buffer, buffer);
	}
	free(buffer);
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	char		*ptr;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	ptr = ft_write(str);
	str = save(str);
	return (ptr);
}
