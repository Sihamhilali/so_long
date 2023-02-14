/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmaps_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:25:37 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/13 17:19:59 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	check_toop_bonus(t_list *data)
{
	int	i;

	i = 0;
	while (data->table[0][i])
	{
		if (data->table[0][i] != '1' || data->table[0][i] == '\n')
		{
			ft_putstr("Error\n");
			exit(0);
		}
		i++;
	}
}

void	check_down_bonus(t_list *data)
{
	int	i;

	i = 0;
	while (data->table[data->line][i])
	{
		if (data->table[data->line][i] != '1')
		{
			ft_putstr("Error\n");
			exit(0);
		}
		i++;
	}
}

void	checkleft_bonus(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = data->line;
	while (data->table[j][i] != '\n' && data->table[j][i])
	{
		i++;
	}
	data->col = i - 1;
	while (j >= 0 && data->table[j][data->col])
	{
		if (data->table[j][data->col] != '1')
		{
			ft_putstr("Error\n");
			exit(0);
		}
		j--;
	}
}

void	checkright_bonus(t_list *data)
{
	int	x;

	x = 0;
	while (data->table[x][0] && x < data->line)
	{
		if (data->table[x][0] != '1')
		{
			ft_putstr("Error\n");
			exit(0);
		}
		x++;
	}
}