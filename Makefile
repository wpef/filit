# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 22:58:04 by fde-monc          #+#    #+#              #
#    Updated: 2016/01/08 17:31:31 by fde-monc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############################
##### >>> VARIABLES <<< ######
##############################

NAME = fillit

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =	ft_checkfile.c \
		ft_allforgrid.c \
		ft_allforttris.c \
		ft_readfile.c \
		main.c

OBJECTS = $(SRC:.c=.o)

INC = ./Includes/

LIB = libft.a

LIB_FILE = $(addprefix $(INC), $(LIB)) 

#############################
##### >>> COMMANDS <<< ######
#############################

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB_FILE)
	$(CC) $(CFLAGS) $(OBJECTS) -L $(INC) -lft -I$(INC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $<

$(LIB_FILE) : 
	make nclean -C $(INC)

test : all
	./fillit test.fillit
	@make clean

clean :
	@rm -rf *.o

nclean : all proper

fclean: clean
	@rm -rf $(NAME)

proper : all clean
	@rm -rf ._*
	@rm -rf *.swp

update :
	cp -Rf ../Libft/* ./Includes

re: fclean all
