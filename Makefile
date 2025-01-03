NAME = libftprintf.a

MY_SOURCES = \
			 ft_printf.c \
			 helpers.c \
			 types.c \
			 types_nbr.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
