/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:42:29 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/16 14:35:06 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

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

int	ft_mmouse(void)
{
	return (exit(0), 0);
}

void	fun(t_list *data)
{
	init_ptr_bonus(&data);
	mlx_hook(data->m_new_w, 2, 0, ft_key_hook_bonus, data);
	backtracking_collect(data);
	backtracking_exit(data);
	mlx_hook(data->m_new_w, 17, 0, ft_mmouse, data);
	mlx_loop_hook(data->m_init, pics2_bonus, data);
	mlx_loop(data->m_init);
}

int	main(int ac, char	**av)
{
	int		fd;
	t_list	*data;

	if (ac == 2)
	{
		data = (t_list *)malloc(sizeof(t_list));
		ber(av[1]);
		inisia_bonus(data);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			exit(1);
		check_line_bonus(fd, data);
		data->m_init = mlx_init();
		if (!data->m_init)
			msg_bonus(data, "Error\n");
		data->t_len = ft_strlen(*data->table);
		data->t_size = hi(data->table) * 50;
		fun(data);
	}
	return (0);
}
