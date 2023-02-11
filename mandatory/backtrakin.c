/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrakin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:59:40 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/11 20:48:21 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	position1(char **arr, int x, int y, int c)
{
	if (c == 0)
		return (1);
	if (arr[x][y] == 'E')
		return (0);
	if (arr[x][y] == '1')
		return (0);
	arr[x][y] = '1';
	if (position1(arr, x, y + 1, c))
		return (1);
	if (position1(arr, x, y - 1, c))
		return (1);
	if (position1(arr, x + 1, y, c))
		return (1);
	if (position1(arr, x - 1, y, c))
		return (1);
	return (0);
}

void	backtracking_collect(t_map *data)
{
	char	**arr1;
	int		i;

	i = 0;
	arr1 = (char **)malloc(sizeof(char *) * (data->t_size + 1));
	if (!arr1)
		exit(1);
	while (i < data->t_size)
	{
		arr1[i] = ft_strdup(data->table[i]);
		i++;
	}
	arr1[i] = NULL;
	if (position1(arr1, *(data->x_p), *(data->y_p), data->collect) == 0)
	{
		ft_putstr("Error\nThe player has nothing to eat.\n");
		exit (0);
	}
	i = 0;
	while (arr1[i])
		free(arr1[i++]);
	free(arr1);
}

//int	position(char **map, int i, int j)
//{
//	if (map[i][j] == 'E')
//		return (1);
//	if (map[i][j] == '1')
//		return (0);
//	map[i][j] = '1';
//	if (position(map, i, j + 1))
//		return (1);
//	if (position(map, i, j - 1))
//		return (1);
//	if (position(map, i + 1, j))
//		return (1);
//	if (position(map, i - 1, j))
//		return (1);
//	return (0);
//}

//void	backtracking(t_map *data)
//{
//	char	**arr1;
//	int		i;
//
//	i = 0;
//	arr1 = (char **)malloc(sizeof(char *) * (data->j + 1));
//	if (!arr1)
//		exit(1);
//	while (i < data->j)
//	{
//		arr1[i] = ft_strdup(data->table[i]);
//		i++;
//	}
//	arr1[i] = NULL;
//	if (position(arr1, data->x_p, data->y_p) == 0)
//	{
//		ft_putstr ("Error\nThe player has no way out.\n");
//		exit (0);
//	}
//	i = 0;
//	while (arr1[i])
//		free(arr1[i++]);
//	free(arr1);
//}
