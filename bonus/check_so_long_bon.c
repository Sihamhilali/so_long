/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_so_long_bon.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:17:17 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/13 17:15:17 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	checks_bonus(t_list *data)
{
	check_toop(data);
	check_down(data);
	checkleft(data);
	checkright(data);
	check_player(data);
	check_c(data);
	check_e(data);
	care(data);
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
			exit(1);
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
	while (data->str[0] != 0)
	{
		k = ft_strjoin(k, data->str);
		free(data->str);
		data->str = get_next_line(fd);
		if (!data->str || data->str[0] == '\n')
		{
			ft_putstr("Error\n New Line");
			exit(1);
		}
		data->j++;
	}
	lastline(k);
	data->table = ft_split(k, '\n');
	checks(data);
}
