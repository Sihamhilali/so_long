/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inisiali_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:13:24 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/16 14:33:37 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	inisia_bonus(t_list *data)
{
	data->len = 0;
	data->width = 0;
	data->n = 0;
	data->k = 0;
	data->y_p = 0;
	data->x_p = 0;
	data->collect = 0;
	data->move = 0;
	data->str = NULL;
}

void	draw_element(char c, int x, int y, t_list **data)
{
	if (c == '1')
		mlx_put_image_to_window((*data)->m_init,
			(*data)->m_new_w, (*data)->one, x, y);
	else
		mlx_put_image_to_window((*data)->m_init,
			(*data)->m_new_w, (*data)->zer, x, y);
	if (c == 'C')
	{
		mlx_put_image_to_window((*data)->m_init,
			(*data)->m_new_w, (*data)->cake, x, y);
	}
	else if (c == 'P')
		pic_player(x, y, &(*data));
	else if (c == 'E')
		pic_exit(x, y, &(*data));
	else if (c == 'N')
		movi_animation((*data), x, y);
	ft_move(*data);
}

char	functin(t_list *data, int i, int j)
{
	if (data->table[i][j] == '1' || data->table[i][j] == 'P' ||
	data->table[i][j] == 'C' || data->table[i][j] == '0' ||
	data->table[i][j] == 'E' || data->table[i][j] == 'N')
		return (data->table[i][j]);
	return (0);
}

int	pics2_bonus(t_list *data)
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
