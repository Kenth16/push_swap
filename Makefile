# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 18:14:12 by knavarre          #+#    #+#              #
#    Updated: 2024/03/04 15:46:18 by knavarre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
INSTRUCTION = instruction/
LIBFT = libft/
SRC = Erreur.c main.c Algorithme.c Algorithme100.c ft_testfonction.c \
		$(INSTRUCTION)change_list.c \
		$(INSTRUCTION)rotate.c \
		$(INSTRUCTION)rotate_inverse.c \
		$(INSTRUCTION)swap_list.c \
		$(LIBFT)ft_split.c \
		$(LIBFT)libft.c \
		$(LIBFT)libft2.c \
		$(LIBFT)libft3.c 
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJ) 
	@echo "\033[1;32mCompilation terminée !\033[0m"
	@$(CC) $(CFLAGS) -o $@ $(OBJ)
	@echo "\033[1;3;40;33mLe fichier push_swap est prêt !\033[0m"

clean :
	@echo "\033[1;34mLes fichiers ont été supprimés.\033[0m"
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME) libft.a

re : fclean all

.PHONY : all clean fclean re
