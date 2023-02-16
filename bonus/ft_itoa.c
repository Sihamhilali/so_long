/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:27:24 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/15 11:52:42 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

int	ft_c(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*ptr;
	int		t;
	long	nbr;

	nbr = n;
	i = ft_c(n);
	t = 0;
	ptr = malloc((sizeof(char) * (i + 1)));
	if (!ptr)
		return (0);
	if (nbr < 0)
	{
		ptr[0] = '-';
		nbr *= -1;
	}
	ptr[i] = 0;
	while (i && (nbr != 0 || n == 0))
	{
		ptr[--i] = '0' + nbr % 10 ;
		nbr = nbr / 10;
	}
	return (ptr);
}
