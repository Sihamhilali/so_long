/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   photo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:47:58 by selhilal          #+#    #+#             */
/*   Updated: 2023/03/19 09:32:48 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	ft_move(t_list *map)
{
	char	*line;

	line = NULL;
	mlx_string_put(map->m_init, map->m_new_w, 10, 30, 0xFFFFFF, "moves :");
	line = ft_itoa(map->move);
	mlx_string_put(map->m_init, map->m_new_w, 70, 30, 0xFFFFFF, line);
	ft_free((void **)&line);
	line = NULL;
}

void	enmy(t_list **data)
{
	(*data)->enmy = mlx_xpm_file_to_image((*data)->m_init,
			"manda/enmy/11.xpm", &(*data)->width, &(*data)->len);
	if (!(*data)->enmy)
		msg_bonus(*data, "Error\n");
		(*data)->enmy1 = mlx_xpm_file_to_image((*data)->m_init,
			"manda/enmy/12.xpm", &(*data)->width, &(*data)->len);
	if (!(*data)->enmy1)
		msg_bonus(*data, "Error\n");
		(*data)->enmy2 = mlx_xpm_file_to_image((*data)->m_init,
			"manda/enmy/13.xpm", &(*data)->width, &(*data)->len);
	if (!(*data)->enmy2)
		msg_bonus(*data, "Error\n");
		(*data)->enmy3 = mlx_xpm_file_to_image((*data)->m_init,
			"manda/enmy/14.xpm", &(*data)->width, &(*data)->len);
	if (!(*data)->enmy3)
		msg_bonus(*data, "Error\n");
}

void	another_pics(t_list **data)
{
	(*data)->player = mlx_xpm_file_to_image((*data)->m_init,
			"manda/player/a.xpm", &(*data)->width, &(*data)->len);
	if (!(*data)->player)
		msg_bonus(*data, "Error\n");
	(*data)->cake = mlx_xpm_file_to_image((*data)->m_init,
			"manda/cupcake.xpm", &(*data)->width, &(*data)->len);
	if (!(*data)->cake)
		msg_bonus(*data, "Error\n");
	(*data)->exit = mlx_xpm_file_to_image((*data)->m_init,
			"manda/door/hh.xpm", &(*data)->width, &(*data)->len);
	if (!(*data)->exit)
		msg_bonus(*data, "Error\n");
}

void	init_ptr_bonus(t_list **data)
{
	(*data)->m_new_w = mlx_new_window((*data)->m_init,
			((*data)->t_len) * 50, (*data)->t_size, "so_long");
	if (!(*data)->m_new_w)
		msg_bonus(*data, "Error\n");
	(*data)->zer = mlx_xpm_file_to_image((*data)->m_init,
			"manda/wall/one.xpm", &(*data)->width, &(*data)->len);
	if (!(*data)->zer)
		msg_bonus(*data, "Error\n");
	(*data)->one = mlx_xpm_file_to_image((*data)->m_init,
			"manda/wall/zero.xpm", &(*data)->width, &(*data)->len);
	if (!(*data)->one)
		msg_bonus(*data, "Error\n");
	another_pics(data);
	enmy(data);
}
