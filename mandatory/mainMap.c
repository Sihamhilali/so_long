/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:48:20 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/11 20:54:24 by selhilal         ###   ########.fr       */
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
	(*data)->zer = mlx_xpm_file_to_image((*data)->m_init,
			"manda/wall/one.xpm", &(*data)->width, &(*data)->len);
	(*data)->one = mlx_xpm_file_to_image((*data)->m_init,
			"manda/wall/zero.xpm", &(*data)->width, &(*data)->len);
	(*data)->player = mlx_xpm_file_to_image((*data)->m_init,
			"manda/player/a.xpm", &(*data)->width, &(*data)->len);
	(*data)->cake = mlx_xpm_file_to_image((*data)->m_init,
			"manda/cupcake.xpm", &(*data)->width, &(*data)->len);
	(*data)->exit = mlx_xpm_file_to_image((*data)->m_init,
			"manda/door/hh.xpm", &(*data)->width, &(*data)->len);
}

int	ft_mmouse(void)
{
	return (exit(0), 0);
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
		//backtracking_collect(data);
		data->m_init = mlx_init();
		data->t_len = ft_strlen(*data->table);
		data->t_size = hi(data->table) * 50;
		init_ptr(&data);
		pics2(data);
		mlx_hook(data->m_new_w, 2, 0, ft_key_hook, (void *)data);
		mlx_hook(data->m_new_w, 17, 0, ft_mmouse, (void *)data);
		mlx_loop_hook(data->m_init, &pics2, (void *)data);
		mlx_loop(data->m_init);
	}
	return (0);
}
