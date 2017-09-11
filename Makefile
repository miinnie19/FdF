# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/08 10:54:14 by mnaidoo           #+#    #+#              #
#    Updated: 2017/09/11 11:11:00 by mnaidoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -o $(NAME) -I includes/ -I libft/ -lmlx -framework OpenGL -framework AppKit

CFILES = source/fdfread.c source/fdfdraw.c source/fdfmain.c source/fdfkeys.c libft/libft.a

$(NAME):
		$(MAKE) -C libft all
			$(CC) $(CFILES) $(CFLAGS)

all: $(NAME)

clean:
		$(MAKE) -C libft clean

fclean:
		$(MAKE) -C libft fclean
			rm -rf $(NAME)

re: fclean all

.PHONY: run re fclean clean all