# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 13:39:21 by mgo               #+#    #+#              #
#    Updated: 2022/02/15 14:08:03 by mgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
#CDEBUG		=	-fsanitize=address -g
RM			=	rm -rf

INC_LINK	=	-I./inc/ -I./lib/libft/includes/
LIBFT		=	-L./lib/libft -lft

SRC_SHR_LST	=	set_data.c \
				cmds.c \
				operate_cmd.c \
				sort_stack.c \
				sort_stack_a.c \
				sort_stack_b.c \
				retrieve_nums_to_top.c \
				sort_stack_only.c \
				sort_stack_a_three.c \
				sort_reversely_stack_b.c \
				set_array_quick_sorted.c \
				clear_data.c \
				utils_lnkd.c \
				utils_stack.c \
				utils_pivot.c \
				exit.c

SRC_PATH	=	./src/
SRC_LIST	=	push_swap_main.c
SRC_LIST	+=	$(SRC_SHR_LST)
SRC			=	$(addprefix $(SRC_PATH), $(SRC_LIST))

OBJ_PATH	=	./obj/
OBJ_LIST	=	$(SRC_LIST:.c=.o)
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_LIST))

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CDEBUG) $(INC_LINK) -c $< -o $@

B_CHECKER	=	checker
B_SRC_PATH	=	./src/
B_SRC_LIST	=	checker_main.c
B_SRC_LIST	+=	$(SRC_SHR_LST)
B_SRC		=	$(addprefix $(B_SRC_PATH), $(B_SRC_LIST))

B_OBJ_PATH	=	./obj/
B_OBJ_LIST	=	$(B_SRC_LIST:.c=.o)
B_OBJ		=	$(addprefix $(B_OBJ_PATH), $(B_OBJ_LIST))

$(B_OBJ_PATH)%.o	:	$(B_SRC_PATH)%.c
	@mkdir $(B_OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CDEBUG) $(INC_LINK) -c $< -o $@

$(NAME)	:	$(OBJ) libft
	@$(CC) $(CFLAGS) $(CDEBUG) $(INC_LINK) $(LIBFT) $(OBJ) -o $(NAME)
	@printf "Made push_swap!\n"

libft	:
	@make -C ./lib/libft all

all		:	$(NAME)

bonus	:	all $(B_OBJ)
	@$(CC) $(CFLAGS) $(CDEBUG) $(INC_LINK) $(LIBFT) $(B_OBJ) -o $(B_CHECKER)
	@printf "Made checker_bonus!\n"

clean	:
	@make -C ./lib/libft clean
	@$(RM) $(OBJ_PATH)
	@printf "Cleaned objs!\n"

fclean	: clean
	@make -C ./lib/libft fclean
	@$(RM) $(NAME)
	@$(RM) $(B_CHECKER)
	@printf "Cleaned objs and file!\n"

re	:	fclean all

.PHONY	:	all clean fclean re
