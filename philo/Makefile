# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 13:51:32 by lmiguel-          #+#    #+#              #
#    Updated: 2024/06/03 16:40:52 by lmiguel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CC			= cc
FLAGS		= -Wall -Werror -Wextra #-pthread -g -fsanitize=thread

OBJ_DIR		= obj
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

SRC			= $(SOURCES)
SOURCES		=	life.c						\
				philo_state.c				\
				philo.c						\
				table_setup.c				\
				utils.c						\
				utils2.c					\
				
all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: %.c
			mkdir -p $(OBJ_DIR)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			rm -rf $(OBJ_DIR)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re