# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okres <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/15 20:50:57 by okres             #+#    #+#              #
#    Updated: 2017/03/15 20:50:59 by okres            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a

C_NAME = checker
P_NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
C_SRC =	checker_d/do_op.c\
		checker_d/main.c\
		checker_d/pa_pb.c\
		checker_d/ra_rb.c\
		checker_d/sa_sb_ss.c\
		checker_d/work_with_list.c\
		checker_d/flags.c\
		checker_d/rra_rrb_rrr.c

P_SRC = push_swap_d/bum_bum.c\
		push_swap_d/choose_help.c\
		push_swap_d/main.c\
		push_swap_d/choose.c\
		push_swap_d/db_linklist_quick_sort.c\
		push_swap_d/differ_sorts.c\
		push_swap_d/help_func.c\
		push_swap_d/other.c\
		push_swap_d/pa_pb.c\
		push_swap_d/put.c\
		push_swap_d/r_m_sort.c\
		push_swap_d/ra_rb.c\
		push_swap_d/rra_rrb_rrr.c\
		push_swap_d/work_with_list.c\
		push_swap_d/transcript.c\
		push_swap_d/sa_sb_ss.c\
		push_swap_d/llist_a.c\
		push_swap_d/optimize1.c

C_OBJ = $(C_SRC:.c=.o)
P_OBJ = $(P_SRC:.c=.o)

all:	$(LIB) $(C_NAME) $(P_NAME)

$(LIB):
		make -C ./libft

$(C_NAME): $(C_OBJ) 
		@$(CC) $(CFLAGS) $(C_OBJ) -o $(C_NAME) $(LIB)
%.o: %.c
		@$(CC) -c $(CFLAGS) -o $@ $<

$(P_NAME): $(P_OBJ) 
		@$(CC) $(CFLAGS) $(P_OBJ) -o $(P_NAME) $(LIB)
%.o: %.c
		@$(CC) -c $(CFLAGS) -o $@ $<

clean_checker: 
		@rm -f $(C_OBJ)	
clean_push_swap: 
		@rm -f $(P_OBJ)
clean:
		@make clean -C ./libft
		@make clean_checker
		@make clean_push_swap

fclean:
		@make fclean -C ./libft
		@make clean
		@rm -f $(C_NAME)
		@rm -f $(P_NAME)
re:
		@make fclean
		@make all
