/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:29:29 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/16 14:36:31 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>

typedef struct map
{
	int		collect;
	char	p;
	int		m;
	int		j;
	char	c;
	int		x_p;
	int		y_p;
	char	e;
	int		width;
	int		len;
	int		k;
	int		n;
	char	**table;
	void	*player;
	void	*exit;
	void	*cake;
	void	*one;
	void	*zer;
	void	*m_new_w;
	void	*m_init;
	char	*s;
	int		move;
	int		t_len;
	int		t_size;

}			t_map;

# define BUFFER_SIZE 42 

char	*ft_strchr(char *str, int c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *string);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
void	check_line(int fd, t_map *y);
void	checkright(t_map *h);
void	checkleft(t_map *h);
void	check_down(t_map *h);
void	check_toop(t_map *h);
void	check_player(t_map *d);
void	check_c(t_map *k);
void	check_e(t_map *k);
void	pics(t_map	*t);
int		pics2(t_map *u);
void	inisia(t_map *j);
int		hi(char **var);
int		ft_key_hook(int i, t_map *data);
void	*ft_free(char **split);
int		ft_moveup(t_map	*map);
void	ft_putstr(char *s);
int		ft_movedown(t_map	*data);
int		ft_moveleft(t_map	*data);
int		ft_moveright(t_map	*data);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		search(char *str, char *ber);
void	ber(char *str);
void	move(t_map *data);
int		position_p(t_map *d);
void	get_high(t_map *data);
void	backtracking_collect(t_map *data);
void	backtracking_exit(t_map *data);
void	checkma(char **tab, int x, int y, t_map *data);
void	msg(t_map *data, char *str);

#endif