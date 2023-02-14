/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inisiali_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:13:24 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/14 11:48:35 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	inisia_bonus(t_list *data)
{
	//data->len = 0;
	//data->width = 0;
	data->n = 0;
	data->k = 0;
	data->y_p = 0;
	data->x_p = 0;
	data->collect = 0;
	data->str = NULL;
}

void	move_bonus(t_list *data)
{
	(data->move) += 1;
	ft_putnbr(data->move);
	ft_putchar('\n');
}
