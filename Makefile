# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 12:30:31 by selhilal          #+#    #+#              #
#    Updated: 2023/01/27 11:50:05 by selhilal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = test.c 
OBJ = (SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : test
test : test.o get_next_line.h
	$(CC) -o $@ $< get_next_line