/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:39:10 by selhilal          #+#    #+#             */
/*   Updated: 2023/03/19 09:29:19 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	count_word(char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		w++;
		i++;
	}
	return (w);
}

static char	*ft_table(char const *s, char c)
{
	int		len;
	char	*ptr;
	int		i;

	len = count_word(s, c);
	i = 0;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_fe(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		ft_free((void **)&split[i]);
		split[i] = 0;
		i++;
	}
	ft_free((void **)&split);
	split = 0;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		w;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			str[w++] = ft_table(&s[i++], c);
		if (w > 0 && !str[w - 1])
			return (ft_fe(str));
		while (s[i] && s[i] != c)
			i++;
	}
	str[w] = 0;
	return (str);
}
