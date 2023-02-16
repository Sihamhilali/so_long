/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:40:23 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/13 16:18:20 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	nb = n;
	if (nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

int	search(char *str, char *ber)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ber[j] && str[i + 1] == ber[j + 1]
			&& str[i + 2] == ber[j + 2] && str[i + 3] == ber[j + 3]
			&& str[i + 4] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	ber(char *str)
{
	if (search(str, ".ber") == 0)
	{
		ft_putstr("Error\n please extenstion .ber\n");
		exit(0);
	}
}
