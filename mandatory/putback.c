/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putback.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:54:51 by selhilal          #+#    #+#             */
/*   Updated: 2023/03/19 08:35:03 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	pic_player(int x, int y, t_map **data)
{
	mlx_put_image_to_window((*data)->m_init,
		(*data)->m_new_w, (*data)->zer, x, y);
	mlx_put_image_to_window((*data)->m_init,
		(*data)->m_new_w, (*data)->player, x, y);
}

void	pic_exit(int x, int y, t_map **data)
{
	mlx_put_image_to_window((*data)->m_init,
		(*data)->m_new_w, (*data)->zer, x, y);
	mlx_put_image_to_window((*data)->m_init,
		(*data)->m_new_w, (*data)->exit, x, y);
}

void	draw_element(char c, int x, int y, t_map **data)
{
	if (c == '1')
		mlx_put_image_to_window((*data)->m_init,
			(*data)->m_new_w, (*data)->one, x, y);
	else if (c == '0')
		mlx_put_image_to_window((*data)->m_init,
			(*data)->m_new_w, (*data)->zer, x, y);
	else if (c == 'C')
	{
		mlx_put_image_to_window((*data)->m_init,
			(*data)->m_new_w, (*data)->zer, x, y);
		mlx_put_image_to_window((*data)->m_init,
			(*data)->m_new_w, (*data)->cake, x, y);
	}
	else if (c == 'P')
		pic_player(x, y, &(*data));
	else if (c == 'E')
		pic_exit(x, y, &(*data));
}

char	functin(t_map *data, int i, int j)
{
	if (data->table[i][j] == '1' || data->table[i][j] == 'P' ||
	data->table[i][j] == 'C' || data->table[i][j] == '0' ||
	data->table[i][j] == 'E')
		return (data->table[i][j]);
	return (0);
}

int	pics2(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	data->k = 0;
	while (data->table[i])
	{
		j = 0;
		data->n = 0;
		while (data->table[i][j])
		{
			if (functin(data, i, j) == data->table[i][j])
				draw_element(data->table[i][j], data->n, data->k, &data);
			else
			{
				ft_putstr("Error\n WAA LMAP!!!!!");
				exit(0);
			}
			j++;
			data->n += 50;
		}
		data->k += 50;
		i++;
	}
	return (0);
}
