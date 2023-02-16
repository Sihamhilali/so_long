/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinside_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:16:34 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/16 14:33:06 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	msg_bonus(t_list *data, char *str)
{
	ft_putstr(str);
	ft_free(data->table);
	exit(0);
}

void	check_player_bonus(t_list *d)
{
	int	i;
	int	j;
	int	l;

	l = 0;
	i = 0;
	while (d->table[i])
	{
		j = 0;
		while (d->table[i][j])
		{
			if (d->table[i][j] == 'P')
			{
				l++;
			}
			j++;
		}
		i++;
	}
	if (l < 1 || l > 1)
		msg_bonus(d, "Error\n one player !!\n");
}

void	check_e_bonus(t_list *data)
{
	int	i;
	int	j;
	int	h;

	h = 0;
	i = 0;
	j = 0;
	while (data->table[j])
	{
		i = 0;
		while (data->table[j][i])
		{
			if (data->table[j][i] == 'E')
			h++;
		i++;
		}
		j++;
	}
	if (h < 1 || h > 1)
		msg_bonus(data, " Error\n one Exit !!\n");
}

void	check_c_bonus(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->table[j])
	{
		i = 0;
		while (data->table[j][i])
		{
			if (data->table[j][i] == 'C')
				data->collect++;
		i++;
		}
		j++;
	}
	if (data->collect < 1)
		msg_bonus(data, "Error\n one or more food !!\n");
}

void	check_n_bonus(t_list *data)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	j = 0;
	while (data->table[j])
	{
		i = 0;
		while (data->table[j][i])
		{
			if (data->table[j][i] == 'N')
				n++;
		i++;
		}
		j++;
	}
	if (n < 1)
		msg_bonus(data, "Error\n one or more Enemy !!\n");
}
