NAME = push_swap

CC = cc

MAKE = make

INCLUDES = -I./libft

CFLAGS =  -Wall -Werror -Wextra $(INCLUDES)

LDFLAGS = -L./libft -lft

DEPS = ./libft/libft.h

# TODO: Remove print_data.c before submitting, it's just for debugging
SRCS = ./push_swap.c \
		./sort_stack.c \
		./calculate_indexes.c \
		./calculate_indexes_helpers.c \
		./data_initialisation.c \
		./print_debug_info.c \
		./prepare_b.c \
		./prepare_b_helpers.c \
		./complete_next_move.c \
		./input_validity_check.c \
		./sort_a.c \
		./sort_a_helpers.c \
		./srcs/push_a.c \
		./srcs/push_b.c \
		./srcs/swap_a.c \
		./srcs/swap_b.c \
		./srcs/swap_both.c \
		./srcs/rotate_a.c \
		./srcs/rotate_b.c \
		./srcs/rotate_both.c \
		./srcs/reverse_rotate_a.c \
		./srcs/reverse_rotate_b.c \
		./srcs/reverse_rotate_both.c \
		./compute_optimal_rotation.c \
		./select_optimal_rotation.c \
		./execute_instructions.c

OBJS = $(notdir $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS) 
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS) $(LDFLAGS)

$(OBJS): $(SRCS) $(DEPS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f push_swap
	$(MAKE) -C ./libft fclean

re: fclean all

test6: all
	rm -f $(OBJS)
	./push_swap $$(cat 6.txt)

test6_2: all
	rm -f $(OBJS)
	./push_swap $$(cat 6_2.txt)

test20: all
	rm -f $(OBJS)
	./push_swap $$(cat 20.txt)

test100: all
	rm -f $(OBJS)
	leaks -atExit -- ./push_swap $$(cat 100.txt)

test500: all
	rm -f $(OBJS)
	leaks -atExit -- ./push_swap $$(cat 500.txt)

test_leaks: all
	leaks -atExit -- ./push_swap

