/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhppk _bonus2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:23:22 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/16 14:27:05 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	ft_moveup_bonus2(t_list *data)
{
	if (data->table[data->x_p - 1][data->y_p] != '1' &&
		data->table[data->x_p - 1][data->y_p] != 'E' &&
		data->table[data->x_p - 1][data->y_p] != 'N')
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
		data->move++;
	}
}

void	ft_movedown_bonus2(t_list *data)
{
	if (data->table[data->x_p + 1][data->y_p] != '1' &&
		data->table[data->x_p + 1][data->y_p] != 'E' &&
		data->table[data->x_p + 1][data->y_p] != 'N')
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
		data->move++;
	}
}

void	ft_moveleft_bonus2(t_list *data)
{
	if (data->table[data->x_p][data->y_p - 1] != '1' &&
		data->table[data->x_p][data->y_p - 1] != 'E' &&
		data->table[data->x_p][data->y_p - 1] != 'N')
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
		data->move++;
	}
}

void	ft_moveright_bonus2(t_list *data)
{
	if (data->table[data->x_p][data->y_p + 1] != '1' &&
		data->table[data->x_p][data->y_p + 1] != 'E' &&
		data->table[data->x_p][data->y_p + 1] != 'N')
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
		data->move++;
	}
}
