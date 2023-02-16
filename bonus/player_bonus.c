/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:32:03 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/16 12:48:27 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

int	ft_key_hook_bonus(int i, t_list *data)
{
	if (i == 13 || i == 126)
		ft_moveup_bonus(data);
	else if (i == 1 || i == 125)
		ft_movedown_bonus(data);
	else if (i == 0 || i == 123)
		ft_moveleft_bonus(data);
	else if (i == 2 || i == 124)
		ft_moveright_bonus(data);
	else if (i == 53)
		exit(0);
	return (0);
}
