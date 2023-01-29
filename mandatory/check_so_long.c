/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:14:22 by selhilal          #+#    #+#             */
/*   Updated: 2023/01/28 17:58:49 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_line(int fd)
{
	char	*s;
	char	**t;
	int		i;

	s = get_next_line(fd);
	i = 0;
	t = malloc((sizeof(char *) * 40));
	while (s)
	{
		t[i++] = ft_strdup(s);
		free(s);
		s = get_next_line(fd);
	}
	i = 0;
	while (t[i] != '\n' && t[i])
	{
		if (t[i] != '1')
		{
			write(1, "error in map\n", 13);
			exit(0);
		}
		i++;
	}
}

int	main(int arc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	mapre(fd);
	return (0);
}
