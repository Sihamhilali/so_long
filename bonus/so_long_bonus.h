/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:17:42 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/14 11:51:58 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>

typedef struct list
{
	char	**table;
	int		line;
	int		collect;
	char	*str;
	int		col;
	int		move;
	int		j;
	int		x_p;
	int		y_p;
	int		k;
	int		n;
	void	*player;
	void	*exit;
	void	*cake;
	void	*one;
	void	*zer;
	void	*m_new_w;
	void	*m_init;
}			t_list;

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

char	*ft_strchr(char *str, int c);
int		ft_strlen(char *s);
void	*ft_memcpy(void *dest, void *src, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *string);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	*ft_free(char **split);
void	check_c(t_list *data);
void	check_e(t_list *data);
void	check_n(t_list *data);
void	check_player(t_list *d);
void	care(t_list *data);
void	checkright(t_list *data);
void	checkleft(t_list *data);
void	check_down(t_list *data);
void	check_toop(t_list *data);
void	check_line_bonus(int fd, t_list *data);
int		search(char *str, char *ber);
void	ber(char *str);

#endif