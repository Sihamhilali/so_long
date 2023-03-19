/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:14:22 by selhilal          #+#    #+#             */
/*   Updated: 2023/03/19 11:03:32 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checks(t_map *data)
{
	get_high(data);
	check_toop(data);
	check_down(data);
	checkleft(data);
	checkright(data);
	check_player(data);
	check_c(data);
	check_e(data);
}

void	get_high(t_map *data)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (data->table[j + 1][k] && data->table[j + 1][k] != '\n')
		k++;
	j = 0;
	while (data->table[j])
	{
		i = 0;
		while (data->table[j][i] && data->table[j][i] != '\n')
		i++;
		if (k != i)
		{
			ft_putstr("Error\n");
			exit(1);
		}
		j++;
	}
}

void	lastline(char *k)
{
	if (k[ft_strlen(k) - 1] != '1')
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

void	check_line(int fd, t_map *data)
{
	char	*k;

	data->j = -1;
	k = ft_strdup("");
	data->s = get_next_line(fd);
	if (!*data->s)
		exit(0);
	while (data->s)
	{
		if (!data->s || data->s[0] == '\n')
		{
			ft_putstr("Error\n New Line");
			exit(1);
		}
		k = ft_strjoin(k, data->s);
		ft_free((void **)&data->s);
		data->s = get_next_line(fd);
		data->j++;
	}
	lastline(k);
	data->table = ft_split(k, '\n');
	ft_free((void **)&k);
	checks(data);
}
