/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:06:56 by selhilal          #+#    #+#             */
/*   Updated: 2023/03/17 20:01:04 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*full_file(char *string)
{
	int		i;
	char	*typ;

	i = 0;
	if (!string[i])
		return (NULL);
	while (string[i] && string[i] != '\n')
		i++;
	typ = (char *)malloc(sizeof(char) * (i + 2));
	if (!typ)
		return (0);
	i = -1;
	while (string[++i] && string[i] != '\n')
		typ[i] = string[i];
	if (string[i] == '\n')
	{
		typ[i] = string[i];
		i++;
	}
	typ[i] = '\0';
	return (typ);
}

void	ft_free(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*full_line(char *typ)
{
	int		i;
	char	*string;

	i = 0;
	while (typ[i] != '\n' && typ[i] != '\0')
		i++;
	if (typ[i] == '\0')
		return (ft_free((void **)&typ), NULL);
	string = ft_substr(typ, i + 1, ft_strlen(typ) - i);
	ft_free((void **)&typ);
	if (!string)
		return (NULL);
	if (*string == '\0')
	{
		ft_free((void **)&string);
		return (NULL);
	}
	return (string);
}

char	*get_next_line(int fd)
{
	char		*typ;
	char		*buffer;
	int			size;
	static char	*string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	size = 1;
	while (!ft_strchr(string, '\n') && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
			return (ft_free((void **)&buffer), ft_free((void **)&string), NULL);
		buffer[size] = '\0';
		string = ft_strjoin(string, buffer);
	}
	ft_free((void **)&buffer);
	if (!string[0] || !string)
		return (ft_free((void **)&string), string = NULL);
	typ = full_file(string);
	string = full_line(string);
	return (typ);
}
