/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putback_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:34:06 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/16 14:34:36 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	pic_player(int x, int y, t_list **data)
{
	mlx_put_image_to_window((*data)->m_init,
		(*data)->m_new_w, (*data)->player, x, y);
}

void	pic_exit(int x, int y, t_list **data)
{
	mlx_put_image_to_window((*data)->m_init,
		(*data)->m_new_w, (*data)->exit, x, y);
}

void	pic_enmy(t_list *data, int x, int y)
{
	static int	i;

	if (i == 4)
		i = 0;
	if (i == 0)
		mlx_put_image_to_window(data->m_init,
			data->m_new_w, data->enmy, x, y);
	else if (i == 1)
		mlx_put_image_to_window(data->m_init,
			data->m_new_w, data->enmy1, x, y);
	else if (i == 2)
		mlx_put_image_to_window(data->m_init,
			data->m_new_w, data->enmy2, x, y);
	else if (i == 3)
		mlx_put_image_to_window(data->m_init,
			data->m_new_w, data->enmy3, x, y);
	else
		mlx_put_image_to_window(data->m_init,
			data->m_new_w, data->enmy, x, y);
	i++;
}

void	mov_enmy(t_list *data, int x, int y)
{
	int	res;
	int	i;
	int	j;

	i = x;
	j = y;
	x = rand() % 3 - 1;
	y = rand() % 3 - 1;
	res = rand() % 2;
	if (res == 0)
		x = 0;
	else
		y = 0;
	if (data->table[i + x][j + y] == 'P')
	{
		ft_putstr("hahaha...klak\n");
		exit (0);
	}
	if (data->table[i + x][j + y] == '0')
	{
			data->table[i + x][j + y] = 'N';
			data->table[i][j] = '0';
			i = i + x;
			j = j + y;
	}
}

int	movi_animation(t_list *data, int x, int y)
{
	static int	j;
	int			k;
	int			l;

	k = 0;
	while (data->table[k])
	{
		l = 0;
		while (data->table[k][l])
		{
			if (data->table[k][l] == 'N')
			{
				pic_enmy(data, x, y);
				if (j == 100)
				{
					j = 0;
					mov_enmy(&(*data), k, l);
				}
				j++;
			}
			l++;
		}
		k++;
	}
	return (0);
}
