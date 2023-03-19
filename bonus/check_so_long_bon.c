/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_so_long_bon.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:17:17 by selhilal          #+#    #+#             */
/*   Updated: 2023/03/19 09:28:57 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	checkenmy(t_list *data)
{
	int	i;
	int	j;
	int	y;

	y = 0;
	i = 0;
	while (data->table[i])
	{
		j = 0;
		while (data->table[i][j])
		{
			if (data->table[i][j] == 'N')
				y++;
			j++;
		}
		i++;
	}
	if (y < 1)
		msg_bonus(data, "Error\n one or more enemy !!\n");
}

void	checks_bonus(t_list *data)
{
	check_toop_bonus(data);
	check_down_bonus(data);
	checkleft_bonus(data);
	checkright_bonus(data);
	check_player_bonus(data);
	check_c_bonus(data);
	check_e_bonus(data);
	checkenmy(data);
}

void	get_high_bonus(t_list *data)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (data->table[j + 1][k] && data->table[j + 1][k] != '\n')
		k++;
	j = 0;
	while (data->table[j])
	{
		i = 0;
		while (data->table[j][i] && data->table[j][i] != '\n')
		i++;
		if (k != i)
		{
			ft_putstr("Error\n");
			exit(0);
		}
		j++;
	}
}

void	lastline_bonus(char *k)
{
	if (k[ft_strlen(k) - 1] != '1')
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

void	check_line_bonus(int fd, t_list *data)
{
	char	*k;

	data->j = -1;
	k = ft_strdup("");
	data->str = get_next_line(fd);
	if (!*data->str)
		exit(0);
	while (data->str)
	{
		if (!data->str || data->str[0] == '\n')
		{
			ft_putstr("Error\n New Line");
			exit(1);
		}
		k = ft_strjoin(k, data->str);
		ft_free((void **)&data->str);
		data->str = get_next_line(fd);
		data->j++;
	}
	lastline_bonus(k);
	data->table = ft_split(k, '\n');
	ft_free((void **)&k);
	checks_bonus(data);
}
