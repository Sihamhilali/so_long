/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putback_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:34:06 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/14 11:50:51 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	pic_player(int x, int y, t_list **data)
{
	mlx_put_image_to_window((*data)->m_init,
		(*data)->m_new_w, (*data)->zer, x, y);
	mlx_put_image_to_window((*data)->m_init,
		(*data)->m_new_w, (*data)->player, x, y);
}

void	pic_exit(int x, int y, t_list **data)
{
	mlx_put_image_to_window((*data)->m_init,
		(*data)->m_new_w, (*data)->zer, x, y);
	mlx_put_image_to_window((*data)->m_init,
		(*data)->m_new_w, (*data)->exit, x, y);
}

void	draw_element(char c, int x, int y, t_list **data)
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

int	pics2(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	data->k = 0;
	mlx_clear_window(data->m_init, data->m_new_w);
	while (data->table[i])
	{
		j = 0;
		data->n = 0;
		while (data->table[i][j])
		{
			if (data->table[i][j] == '1' || data->table[i][j] == 'P' ||
				data->table[i][j] == 'C' || data->table[i][j] == '0' ||
				data->table[i][j] == 'E')
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
