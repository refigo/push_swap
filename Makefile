# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 13:39:21 by mgo               #+#    #+#              #
#    Updated: 2022/02/15 15:21:27 by mgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
BONUS		=	checker
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
#CDEBUG		=	-fsanitize=address -g
RM			=	rm -rf

INC_LINK	=	-I./inc/ -I./lib/libft/includes/
LIBFT		=	-L./lib/libft -lft


SRC_PATH	=	./src/

SRC_LIST	=	push_swap_main.c
SRC			=	$(addprefix $(SRC_PATH), $(SRC_LIST))

SRC_LIST_B	=	checker_main.c
SRC_B		=	$(addprefix $(SRC_PATH), $(B_SRC_LIST))

SRC_LIST_SHR	=	set_data.c \
					cmds.c \
					operate_cmd.c \
					sort_stack.c \
					sort_stack_a.c \
					sort_stack_b.c \
					sort_stack_only.c \
					sort_stack_a_three.c \
					sort_reversely_stack_b.c \
					set_array_quick_sorted.c \
					retrieve_nums_to_top.c \
					clear_data.c \
					utils_lnkd.c \
					utils_stack.c \
					utils_pivot.c \
					exit.c
SRC_SHR			=	$(addprefix $(SRC_PATH), $(SRC_LIST_SHR))


OBJ_PATH	=	./obj/

OBJ_LIST	=	$(SRC_LIST:.c=.o)
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_LIST))

OBJ_LIST_B	=	$(SRC_LIST_B:.c=.o)
OBJ_B		=	$(addprefix $(OBJ_PATH), $(OBJ_LIST_B))

OBJ_LIST_SHR	=	$(SRC_LIST_SHR:.c=.o)
OBJ_SHR			=	$(addprefix $(OBJ_PATH), $(OBJ_LIST_SHR))


$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CDEBUG) $(INC_LINK) -c $< -o $@

$(OBJ_PATH)%.o	:	$(SRC_PATH_B)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CDEBUG) $(INC_LINK) -c $< -o $@

$(OBJ_PATH)%.o	:	$(SRC_PATH_SHR)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CDEBUG) $(INC_LINK) -c $< -o $@


$(NAME)	:	$(OBJ) $(OBJ_SHR) libft
	@$(CC) $(CFLAGS) $(CDEBUG) $(INC_LINK) $(LIBFT) $(OBJ_SHR) $(OBJ) -o $(NAME)
	@printf "Made the push_swap!\n"

libft	:
	@make -C ./lib/libft all

all		:	$(NAME)

bonus	:	$(OBJ_B) $(OBJ_SHR) libft
	@$(CC) $(CFLAGS) $(CDEBUG) $(INC_LINK) $(LIBFT) $(OBJ_SHR) $(OBJ_B) -o $(BONUS)
	@printf "Made the checker!\n"

clean	:
	@make -C ./lib/libft clean
	@$(RM) $(OBJ_PATH)
	@printf "Cleaned objs!\n"

fclean	: clean
	@make -C ./lib/libft fclean
	@$(RM) $(NAME)
	@$(RM) $(BONUS)
	@printf "Cleaned files!\n"

re	:	fclean all

.PHONY	:	all clean fclean re
