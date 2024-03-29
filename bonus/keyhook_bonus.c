/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:26:46 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/16 14:34:03 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

int	position_p_bonus(t_list *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->table[i])
	{
		j = 0;
		while (d->table[i][j])
		{
			if (d->table[i][j] == 'P')
			{
				d->x_p = i;
				d->y_p = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_moveup_bonus(t_list *data)
{
	position_p_bonus(data);
	if (data->table[data->x_p - 1][data->y_p] == 'E' && data->collect == 0)
	{
		ft_putstr("you won\n");
		exit(0);
	}
	if (data->table[data->x_p - 1][data->y_p] == 'N')
	{
		ft_putstr("you lose\n");
		exit(0);
	}
	ft_moveup_bonus2(data);
	pics2_bonus(data);
	return (0);
}

int	ft_movedown_bonus(t_list	*data)
{
	position_p_bonus(data);
	if (data->table[data->x_p + 1][data->y_p] == 'E' && data->collect == 0)
	{
		ft_putstr("you won\n");
		exit(0);
	}
	if (data->table[data->x_p + 1][data->y_p] == 'N')
	{
		ft_putstr("you lose\n");
		exit(0);
	}
	ft_movedown_bonus2(data);
	pics2_bonus(data);
	return (0);
}

int	ft_moveleft_bonus(t_list	*data)
{
	position_p_bonus(data);
	if (data->table[data->x_p][data->y_p - 1] == 'E' && data->collect == 0)
	{
		ft_putstr("you won\n");
		exit(0);
	}
	if (data->table[data->x_p][data->y_p - 1] == 'N')
	{
		ft_putstr("you lose\n");
		exit(0);
	}
	ft_moveleft_bonus2(data);
	pics2_bonus(data);
	return (0);
}

int	ft_moveright_bonus(t_list	*data)
{
	position_p_bonus(data);
	if (data->table[data->x_p][data->y_p + 1] == 'E' && data->collect == 0)
	{
		ft_putstr("you won\n");
		exit(0);
	}
	if (data->table[data->x_p][data->y_p + 1] == 'N')
	{
		ft_putstr("you lose\n");
		exit(0);
	}
	ft_moveright_bonus2(data);
	pics2_bonus(data);
	return (0);
}
