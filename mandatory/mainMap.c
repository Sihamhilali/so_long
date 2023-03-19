/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:48:20 by selhilal          #+#    #+#             */
/*   Updated: 2023/03/19 09:22:42 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	hi(char **var)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (var[i])
	{
		j = 0;
		while (var[i][j] != '\n' && var[i][j])
			j++;
		i++;
	}
	return (i);
}

void	init_ptr(t_map **data)
{
	(*data)->m_new_w = mlx_new_window((*data)->m_init,
			((*data)->t_len) * 50, (*data)->t_size, "so_long");
	if (!(*data)->m_new_w)
		msg(*data, "Error\n");
	(*data)->zer = mlx_xpm_file_to_image((*data)->m_init,
			"manda/wall/one.xpm", &(*data)->width, &(*data)->len);
	if (!(*data)->zer)
		msg(*data, "Error\n");
	(*data)->one = mlx_xpm_file_to_image((*data)->m_init,
			"manda/wall/zero.xpm", &(*data)->width, &(*data)->len);
	if (!(*data)->one)
		msg(*data, "Error\n");
	(*data)->player = mlx_xpm_file_to_image((*data)->m_init,
			"manda/player/a.xpm", &(*data)->width, &(*data)->len);
	if (!(*data)->player)
		msg(*data, "Error\n");
	(*data)->cake = mlx_xpm_file_to_image((*data)->m_init,
			"manda/cupcake.xpm", &(*data)->width, &(*data)->len);
	if (!(*data)->cake)
		msg(*data, "Error\n");
	(*data)->exit = mlx_xpm_file_to_image((*data)->m_init,
			"manda/door/hh.xpm", &(*data)->width, &(*data)->len);
	if (!(*data)->exit)
		msg(*data, "Error\n");
}

int	ft_mmouse(void)
{
	return (exit(0), 0);
}

void	fun(t_map *data)
{
	init_ptr(&data);
	mlx_hook(data->m_new_w, 2, 0, ft_key_hook, (void *)data);
	back_collect(data);
	back_exit(data);
	mlx_hook(data->m_new_w, 17, 0, ft_mmouse, (void *)data);
	mlx_loop_hook(data->m_init, &pics2, (void *)data);
	mlx_loop(data->m_init);
}

int	main(int ac, char	**av)
{
	int		fd;
	t_map	*data;

	if (ac == 2)
	{
		data = (t_map *)malloc(sizeof(t_map));
		ber(av[1]);
		inisia(data);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			exit(1);
		check_line(fd, data);
		data->m_init = mlx_init();
		if (!data->m_init)
			msg(data, "Error\n");
		data->t_len = ft_strlen(*data->table);
		data->t_size = hi(data->table) * 50;
		fun(data);
	}
	return (0);
}
