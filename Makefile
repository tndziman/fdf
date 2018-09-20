# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tndziman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 11:25:45 by tndziman          #+#    #+#              #
#    Updated: 2018/08/15 14:51:25 by tndziman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

NOC = \033[0m
WAC = \033[33m

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = fdf.c \
	  ft_keyboard.c \
	  ft_draw.c \
	  ft_readmap.c \
	  ft_check_line.c \
	  ft_zoom.c


OBJ = $(SRC:.c=.o)

$(NAME) :
	make -C libft/ fclean && make -C libft/
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -o fdf

all : $(NAME)

clean :
	$(RM) $(OBJ)
	make -C libft/ clean
	@echo "$(WAC) all .o files Cleaned$(NOC)"

fclean : clean
	$(RM) $(NAME)
	make -C libft/ fclean
	@echo "$(WAC)Executables Removed!!$(NOC)"

re : fclean all
