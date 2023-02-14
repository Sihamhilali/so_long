# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 12:30:31 by selhilal          #+#    #+#              #
#    Updated: 2023/02/13 16:33:57 by selhilal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BNAME = so_long_bonus
CC = cc

CFLAGS = -Wall -Werror -Wextra 

LINK = -lmlx -framework OpenGL -framework AppKit

SRC = mandatory/check_so_long.c mandatory/checkinsid.c mandatory/get_next_line.c mandatory/get_next_line_utils.c mandatory/mainMap.c mandatory/utils.c mandatory/inisiali.c mandatory/putback.c mandatory/checkmaps.c mandatory/player.c mandatory/keyhook.c mandatory/ft_put.c mandatory/backtrakin.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = bonus/check_so_long_bon.c bonus/checkinside_bonus.c bonus/checkmaps_bonus.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/put_bonus.c bonus/utils_bonus.c bonus/main_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

HED = mandatory/so_long.h
HED_BONUS = bonus/so_long_bonus.h

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
$(NAME) : $(OBJ) $(HED)
	$(CC) $(CFLAGS) $(SRC) $(LINK) -o $(NAME)

bonus : $(BNAME)

$(BNAME) : $(OBJ_BONUS) $(HED_BONUS)
	$(CC) $(CFLAGS) $(SRC_BONUS) $(LINK) -o $(NAME)
	
all : $(NAME) $(BNAME)

clean :
	rm -rf $(OBJ) $(OBJ_BONUS)
fclean : clean
	rm -rf $(NAME)
re : fclean all

.PHONY: re fclean clean all 