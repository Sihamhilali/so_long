/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:05:54 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/16 14:09:58 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	position_p(t_map *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->table[i])
	{
		j = 0;
		while (d->table[i][j])
		{
			if (d->table[i][j] == 'P')
			{
				d->x_p = i;
				d->y_p = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_moveup(t_map *data)
{
	position_p(data);
	if (data->table[data->x_p - 1][data->y_p] == 'E' && data->collect == 0)
	{
		ft_putstr("you won\n");
		exit(0);
	}
	if (data->table[data->x_p - 1][data->y_p] != '1' &&
		data->table[data->x_p - 1][data->y_p] != 'E')
	{
		if (data->table[data->x_p - 1][data->y_p] == 'C')
			data->collect--;
		if (data->collect == 0)
		{
			mlx_destroy_image(data->m_init, data->exit);
				data->exit = mlx_xpm_file_to_image(data->m_init,
					"manda/door/open.xpm", &data->width, &data->len);
		}
		data->table[data->x_p][data->y_p] = '0';
		data->table[data->x_p - 1][data->y_p] = 'P';
		data->x_p -= 1;
		move(data);
	}
	pics2(data);
	return (0);
}

int	ft_movedown(t_map	*data)
{
	position_p(data);
	if (data->table[data->x_p + 1][data->y_p] == 'E' && data->collect == 0)
	{
		ft_putstr("you won\n");
		exit(0);
	}
	if (data->table[data->x_p + 1][data->y_p] != '1' &&
		data->table[data->x_p + 1][data->y_p] != 'E')
	{
		if (data->table[data->x_p + 1][data->y_p] == 'C')
			data->collect--;
		if (data->collect == 0)
		{
			mlx_destroy_image(data->m_init, data->exit);
				data->exit = mlx_xpm_file_to_image(data->m_init,
					"manda/door/open.xpm", &data->width, &data->len);
		}
		data->table[data->x_p][data->y_p] = '0';
		data->table[data->x_p + 1][data->y_p] = 'P';
		data->x_p += 1;
		move(data);
	}
	pics2(data);
	return (0);
}

int	ft_moveleft(t_map	*data)
{
	position_p(data);
	if (data->table[data->x_p][data->y_p - 1] == 'E' && data->collect == 0)
	{
		ft_putstr("you won\n");
		exit(0);
	}
	if (data->table[data->x_p][data->y_p - 1] != '1' &&
		data->table[data->x_p][data->y_p - 1] != 'E')
	{
		if (data->table[data->x_p][data->y_p - 1] == 'C')
			data->collect--;
		if (data->collect == 0)
		{
			mlx_destroy_image(data->m_init, data->exit);
				data->exit = mlx_xpm_file_to_image(data->m_init,
					"manda/door/open.xpm", &data->width, &data->len);
		}
		data->table[data->x_p][data->y_p] = '0';
		data->table[data->x_p][data->y_p - 1] = 'P';
		data->x_p -= 1;
		move(data);
	}
	pics2(data);
	return (0);
}

int	ft_moveright(t_map	*data)
{
	position_p(data);
	if (data->table[data->x_p][data->y_p + 1] == 'E' && data->collect == 0)
	{
		ft_putstr("you won\n");
		exit(0);
	}
	if (data->table[data->x_p][data->y_p + 1] != '1' &&
		data->table[data->x_p][data->y_p + 1] != 'E')
	{
		if (data->table[data->x_p][data->y_p + 1] == 'C')
			data->collect--;
		if (data->collect == 0)
		{
			mlx_destroy_image(data->m_init, data->exit);
				data->exit = mlx_xpm_file_to_image(data->m_init,
					"manda/door/open.xpm", &data->width, &data->len);
		}
		data->table[data->x_p][data->y_p] = '0';
		data->table[data->x_p][data->y_p + 1] = 'P';
		data->x_p += 1;
		move(data);
	}
	pics2(data);
	return (0);
}
