NAME = libftprintf.a

SRCS = ft_printf.c if_conv.c put_conv_base.c put_func.c

LIBFT = ./libft

INCLUDES = ft_printf.h

OBJS = $(SRCS:.c=.o)

LIBFT_OBJS = ./libft/ft_atoi.o ./libft/ft_bzero.o ./libft/ft_isalnum.o ./libft/ft_isalpha.o ./libft/ft_isascii.o ./libft/ft_isdigit.o \
             	./libft/ft_isprint.o ./libft/ft_itoa.o ./libft/ft_memchr.o ./libft/ft_memcmp.o ./libft/ft_memcpy.o ./libft/ft_memmove.o ./libft/ft_memset.o \
             	./libft/ft_split.o ./libft/ft_strchr.o ./libft/ft_strjoin.o ./libft/ft_strlcat.o ./libft/ft_strlcpy.o ./libft/ft_strlen.o \
             	./libft/ft_strncmp.o ./libft/ft_strnstr.o ./libft/ft_strrchr.o ./libft/ft_strtrim.o ./libft/ft_substr.o ./libft/ft_tolower.o ./libft/ft_toupper.o \
             	./libft/ft_strdup.o ./libft/ft_calloc.o ./libft/ft_strmapi.o ./libft/ft_striteri.o ./libft/ft_putchar_fd.o ./libft/ft_putstr_fd.o \
             	./libft/ft_putendl_fd.o ./libft/ft_putnbr_fd.o

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
		$(MAKE) -C $(LIBFT)
		ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

all:	$(NAME)

clean:
		$(RM) $(OBJS)
		$(MAKE) -C $(LIBFT) clean

fclean:	clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIBFT) fclean

re:		fclean all

.PHONY:	all clean fclean re

#test:\
	./test.sh\
\
printf:\
	gcc ft_printf.c if_conv.c put_func.c put_conv_base.c -D TEST -o printf\
\
ft_printf:\
	gcc ft_printf.c if_conv.c put_func.c put_conv_base.c -D TEST -D FT_PRINTF -o ft_printf\
\
clean:\
	rm -rf printf ft_printf\