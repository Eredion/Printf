# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asegovia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 12:00:03 by asegovia          #+#    #+#              #
#    Updated: 2019/12/12 14:54:09 by asegovia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

C_FILES = ft_printf.c printstr.c flags.c ft_atoi.c ft_strchr.c\
		  ft_strlen.c printp.c ft_strdup.c printd.c printx.c printper.c\
		  ft_strjoin.c

O_FILES = $(C_FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

all:  
	gcc -c $(FLAGS) $(C_FILES)
	ar rc $(NAME) $(O_FILES)
	ranlib $(NAME)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
