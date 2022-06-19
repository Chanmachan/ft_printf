NAME = libftprintf.a

SRCS = ft_printf.c if_conv.c put_conv_base.c put_func.c

INCLUDES = ft_printf.h

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS) $(INCLUDES)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re\

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