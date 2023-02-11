/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmaps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:29:17 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/11 15:48:17 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_toop(t_map *data)
{
	int	i;

	i = 0;
	while (data->table[0][i])
	{
		if (data->table[0][i] != '1' || data->table[0][i] == '\n')
		{
			ft_putstr("Error\n 9ad dak lfo9 3afak\n");
			exit(0);
		}
		i++;
	}
}

void	check_down(t_map *data)
{
	int	i;

	i = 0;
	while (data->table[data->j][i])
	{
		if (data->table[data->j][i] != '1')
		{
			ft_putstr("Error\n 9ad dak lta7t 3afak\n");
			exit(0);
		}
		i++;
	}
}

void	checkleft(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	j = data->j;
	while (data->table[j][i] != '\n' && data->table[j][i])
	{
		i++;
	}
	data->m = i - 1;
	while (j >= 0 && data->table[j][data->m])
	{
		if (data->table[j][data->m] != '1')
		{
			ft_putstr("Error\n 9ad dak lisr 3afak\n");
			exit(0);
		}
		j--;
	}
}

void	checkright(t_map *data)
{
	int	x;

	x = 0;
	while (data->table[x][0] && x < data->j)
	{
		if (data->table[x][0] != '1')
		{
			ft_putstr("Error\n 9ad dak limen 3afak\n");
			exit(0);
		}
		x++;
	}
}

void	newlin(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[i] == '\n')
		{
			if (data[i - 1] == '1')
			{
				i++;
			}
			else if (data[i - 1] != '1')
			{
				ft_putstr("Error\n no no 9ad dakchi\n");
				exit(1);
			}
		}
		i++;
	}
}
