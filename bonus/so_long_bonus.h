/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:17:42 by selhilal          #+#    #+#             */
/*   Updated: 2023/02/16 14:35:45 by selhilal         ###   ########.fr       */
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
	int		t_len;
	int		t_size;
	int		len;
	int		width;
	void	*enmy;
	void	*enmy1;
	void	*enmy2;
	void	*enmy3;

}			t_list;

# define BUFFER_SIZE 42

void	*ft_free(char **split);
char	**ft_split(char const *s, char c);
void	checks_bonus(t_list *data);
void	get_high_bonus(t_list *data);
void	lastline_bonus(char *k);
void	check_line_bonus(int fd, t_list *data);
void	msg_bonus(t_list *data, char *str);
void	check_player_bonus(t_list *d);
void	check_e_bonus(t_list *data);
void	check_c_bonus(t_list *data);
void	check_n_bonus(t_list *data);
void	checkenmy(t_list *data);
void	check_toop_bonus(t_list *data);
void	check_down_bonus(t_list *data);
void	checkleft_bonus(t_list *data);
void	checkright_bonus(t_list *data);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *string);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void	move_bonus(t_list *data);
void	inisia_bonus(t_list *data);
int		position_p_bonus(t_list *d);
void	ft_moveup_bonus2(t_list *data);
void	ft_movedown_bonus2(t_list *data);
void	ft_moveleft_bonus2(t_list *data);
void	ft_moveright_bonus2(t_list *data);
int		ft_moveup_bonus(t_list *data);
int		ft_movedown_bonus(t_list	*data);
int		ft_moveleft_bonus(t_list	*data);
int		ft_moveright_bonus(t_list	*data);
void	init_ptr_bonus(t_list **data);
int		ft_key_hook_bonus(int i, t_list *data);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		search(char *str, char *ber);
void	ber(char *str);
int		pics2_bonus(t_list *data);
void	backtracking_exit(t_list *data);
void	backtracking_collect(t_list *data);
char	*ft_itoa(int n);
void	ft_move(t_list *map);
void	pic_player(int x, int y, t_list **data);
void	pic_exit(int x, int y, t_list **data);
void	pic_enmy(t_list *data, int x, int y);
void	mov_enmy(t_list *data, int x, int y);
int		movi_animation(t_list *data, int x, int y);
void	draw_element(char c, int x, int y, t_list **data);

#endif