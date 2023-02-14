/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inisiali.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:06:18 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/14 15:14:53 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	inisia(t_map *data)
{
	data->len = 0;
	data->width = 0;
	data->n = 0;
	data->k = 0;
	data->y_p = 0;
	data->x_p = 0;
	data->collect = 0;
	data->s = NULL;
}

void	move(t_map *data)
{
	(data->move) += 1;
	ft_putnbr(data->move);
	ft_putchar('\n');
}

char	*ft_strdup(char *string)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * ft_strlen(string)+1);
	if (!ptr)
		return (NULL);
	while (string[i])
	{
		ptr[i] = string[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}