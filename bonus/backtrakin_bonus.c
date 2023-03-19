/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrakin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:38:31 by selhilal          #+#    #+#             */
/*   Updated: 2023/03/19 09:28:36 by selhilal         ###   ########.fr       */
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

int	for_e(char **str, int i, int j)
{
	if (str[i][j] == 'E')
		return (1);
	if (str[i][j] == '1')
		return (0);
	str[i][j] = '1';
	if (for_e(str, i, j + 1))
		return (1);
	if (for_e(str, i, j - 1))
		return (1);
	if (for_e(str, i + 1, j))
		return (1);
	if (for_e(str, i - 1, j))
		return (1);
	return (0);
}

int	for_c(char **str, int x, int y)
{
	int	c;

	c = count_c(str);
	if (c == 0)
		return (1);
	if (str[x][y] == 'E')
		return (0);
	if (str[x][y] == '1')
		return (0);
	str[x][y] = '1';
	if (for_c(str, x, y + 1))
		return (1);
	if (for_c(str, x, y - 1))
		return (1);
	if (for_c(str, x + 1, y))
		return (1);
	if (for_c(str, x - 1, y))
		return (1);
	return (0);
}

void	back_collect(t_list *data)
{
	char	**str;
	int		n;

	n = 0;
	str = (char **)malloc(sizeof(char *) * (data->j + 2));
	if (!str)
		exit(1);
	while (n < data->j + 1)
	{
		str[n] = ft_strdup(data->table[n]);
		n++;
	}
	str[n] = 0;
	position_p_bonus(data);
	if (for_c(str, data->x_p, data->y_p) == 0)
	{
		ft_putstr("Error\nThe player has nothing to eat.\n");
		exit (0);
	}
	n = 0;
	while (str[n])
		ft_free((void **)&str[n++]);
	ft_free((void **)&str);
}

void	back_exit(t_list *data)
{
	char	**str;
	int		n;

	n = 0;
	str = (char **)malloc(sizeof(char *) * (data->j + 2));
	if (!str)
		exit(1);
	while (n < data->j + 1)
	{
		str[n] = ft_strdup(data->table[n]);
		n++;
	}
	str[n] = 0;
	position_p_bonus(data);
	if (for_e(str, data->x_p, data->y_p) == 0)
	{
		ft_putstr ("Error\nThe player has no way out.\n");
		exit (0);
	}
	n = 0;
	while (str[n])
		ft_free((void **)&str[n++]);
	ft_free((void **)&str);
}
