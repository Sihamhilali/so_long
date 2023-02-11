# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 12:30:31 by selhilal          #+#    #+#              #
#    Updated: 2023/02/11 19:13:03 by selhilal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra 

LINK = -lmlx -framework OpenGL -framework AppKit

SRC = mandatory/check_so_long.c mandatory/checkinsid.c mandatory/get_next_line.c mandatory/get_next_line_utils.c mandatory/mainMap.c mandatory/utils.c mandatory/inisiali.c mandatory/putback.c mandatory/checkmaps.c mandatory/player.c mandatory/keyhook.c mandatory/ft_put.c mandatory/backtrakin.c
OBJ = $(SRC:.c=.o)

HED = mandatory/so_long.h

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
$(NAME) : $(OBJ) $(HED)
	$(CC) $(CFLAGS) $(SRC) $(LINK) -o $(NAME)
	
all : $(NAME)

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all

.PHONY: re fclean clean all 