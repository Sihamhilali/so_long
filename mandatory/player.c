/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:39:30 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/11 12:57:02 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_key_hook(int i, t_map *data)
{
	if (i == 13 || i == 126)
		ft_moveup(data);
	else if (i == 1 || i == 125)
		ft_movedown(data);
	else if (i == 0 || i == 123)
		ft_moveleft(data);
	else if (i == 2 || i == 124)
		ft_moveright(data);
	else if (i == 53)
		exit(0);
	return (0);
}
