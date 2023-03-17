/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinsid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:43:02 by selhilal          #+#    #+#             */
/*   Updated: 2023/03/17 20:08:37 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	msg(t_map *data, char *str)
{
	ft_putstr(str);
	ft_fe(data->table);
	exit(1);
}

void	check_player(t_map *d)
{
	int	i;
	int	j;
	int	l;

	l = 0;
	i = 0;
	while (d->table[i])
	{
		j = 0;
		while (d->table[i][j])
		{
			if (d->table[i][j] == 'P')
			{
				l++;
			}
			j++;
		}
		i++;
	}
	if (l < 1 || l > 1)
		msg(d, "Error\n one player !!\n");
}

void	check_c(t_map *data)
{
	int	i;
	int	j;
	int	h;

	h = 0;
	i = 0;
	j = 0;
	while (data->table[j])
	{
		i = 0;
		while (data->table[j][i])
		{
			if (data->table[j][i] == 'E')
			h++;
		i++;
		}
		j++;
	}
	if (h < 1 || h > 1)
		msg(data, " Error\n one Exit !!\n");
}

void	check_e(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->table[j])
	{
		i = 0;
		while (data->table[j][i])
		{
			if (data->table[j][i] == 'C')
				data->collect++;
		i++;
		}
		j++;
	}
	if (data->collect < 1)
		msg(data, "Error\n one or more food !!\n");
}
