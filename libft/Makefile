NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_atoi.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_strlen.c \
		ft_putnbr_fd.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_bzero.c \
		ft_strlcpy.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_itoa.c \
		ft_split.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_printf.c \
		handle_c.c \
		handle_s.c \
		handle_p.c \
		handle_d.c \
		handle_u.c \
		handle_lower_x.c \
		handle_upper_x.c \
		get_next_line.c \
		gnl_freemem.c 
		

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) -c $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
