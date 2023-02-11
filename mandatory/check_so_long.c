/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:14:22 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/11 15:29:51 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checks(t_map *data)
{
	check_toop(data);
	check_down(data);
	checkleft(data);
	checkright(data);
	check_player(data);
	check_c(data);
	check_e(data);
}

void	check_line(int fd, t_map *data)
{
	char	*k;

	data->j = -1;
	k = ft_strdup("");
	data->s = get_next_line(fd);
	while (data->s[0] != 0)
	{
		k = ft_strjoin(k, data->s);
		free(data->s);
		data->s = get_next_line(fd);
		data->j++;
	}
	newlin(k);
	if (k[ft_strlen(k) - 1] != '1')
	{
		ft_putstr("Error\n");
		exit(0);
	}
	data->table = ft_split(k, '\n');
	if (data->m == data->j)
	{
		ft_putstr("Error\n no no ... ");
		exit(0);
	}
	checks(data);
}
