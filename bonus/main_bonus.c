/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:42:29 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/13 16:34:14 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"


int	main(int ac, char	**av)
{
	int		fd;
	t_list	*data;


	if (ac == 2)
	{
		data = (t_list *)malloc(sizeof(t_list));
		ber(av[1]);
		//inisia(data);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			exit(1);
		check_line_bonus(fd, data);
	}
}
