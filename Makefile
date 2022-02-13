# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 13:39:21 by mgo               #+#    #+#              #
#    Updated: 2022/02/13 13:33:17 by mgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
CDEBUG		=	-fsanitize=address -g
RM			=	rm -rf

INC_LINK	=	-I./inc/ -I./lib/libft/includes/
LIBFT		=	-L./lib/libft -lft

SRC_PATH	=	./src/
SRC_LIST	=	main.c \
				set_data.c \
				cmds.c \
				operate_cmd.c \
				sort_stack_a.c \
				sort_stack_b.c \
				sort_stack_a_only.c \
				sort_stack_a_three.c \
				sort_reversely_stack_b.c \
				set_array_quick_sorted.c \
				utils_stack.c \
				utils_lnkd.c \
				exit.c \
				test_ps.c
SRC			=	$(addprefix $(SRC_PATH), $(SRC_LIST))

OBJ_PATH	=	./obj/
OBJ_LIST	=	$(SRC_LIST:.c=.o)
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_LIST))

$(NAME)	:	$(OBJ) libft
	$(CC) $(CDEBUG) $(CFLAGS) $(OBJ) $(INC_LINK) $(LIBFT) -o $(NAME)

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CDEBUG) $(CFLAGS) $(INC_LINK) -c $< -o $@

libft	:
	make -C ./lib/libft all

all		:	$(NAME)

clean	:
	@make -C ./lib/libft clean
	$(RM) $(OBJ_PATH)

fclean	: clean
	@make -C ./lib/libft fclean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
