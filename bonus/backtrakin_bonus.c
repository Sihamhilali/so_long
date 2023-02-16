/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrakin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:38:31 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/14 16:45:24 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

int	count_c(char **c)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	j = 0;
	r = 0;
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			if (c[i][j] == 'C')
				r++;
			j++;
		}
		i++;
	}
	return (r);
}

int	position(char **map, int i, int j)
{
	if (map[i][j] == 'E')
		return (1);
	if (map[i][j] == '1')
		return (0);
	map[i][j] = '1';
	if (position(map, i, j + 1))
		return (1);
	if (position(map, i, j - 1))
		return (1);
	if (position(map, i + 1, j))
		return (1);
	if (position(map, i - 1, j))
		return (1);
	return (0);
}

int	position1(char **arr, int x, int y)
{
	int	c;

	c = count_c(arr);
	if (c == 0)
		return (1);
	if (arr[x][y] == 'E')
		return (0);
	if (arr[x][y] == '1')
		return (0);
	arr[x][y] = '1';
	if (position1(arr, x, y + 1))
		return (1);
	if (position1(arr, x, y - 1))
		return (1);
	if (position1(arr, x + 1, y))
		return (1);
	if (position1(arr, x - 1, y))
		return (1);
	return (0);
}

void	backtracking_collect(t_list *data)
{
	char	**arr1;
	int		i;

	i = 0;
	arr1 = (char **)malloc(sizeof(char *) * (data->j + 2));
	if (!arr1)
		exit(1);
	while (i < data->j + 1)
	{
		arr1[i] = ft_strdup(data->table[i]);
		i++;
	}
	arr1[i] = 0;
	position_p_bonus(data);
	if (position1(arr1, data->x_p, data->y_p) == 0)
	{
		ft_putstr("Error\nThe player has nothing to eat.\n");
		exit (0);
	}
	i = 0;
	while (arr1[i])
		free(arr1[i++]);
	free(arr1);
}

void	backtracking_exit(t_list *data)
{
	char	**arr1;
	int		i;

	i = 0;
	arr1 = (char **)malloc(sizeof(char *) * (data->j + 2));
	if (!arr1)
		exit(1);
	while (i < data->j + 1)
	{
		arr1[i] = ft_strdup(data->table[i]);
		i++;
	}
	arr1[i] = 0;
	position_p_bonus(data);
	if (position(arr1, data->x_p, data->y_p) == 0)
	{
		ft_putstr ("Error\nThe player has no way out.\n");
		exit (0);
	}
	i = 0;
	while (arr1[i])
		free(arr1[i++]);
	free(arr1);
}