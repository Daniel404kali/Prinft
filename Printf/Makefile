SOURCE_FILES = ft_printf.c \
			   ft_putchar.c \
			   ft_putnbr.c \
			   ft_putnbr_base.c \
			   ft_putstr.c \
			   ft_strlen.c 


OBJECTS = $(SOURCE_FILES:.c=.o)

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar -crs $@ $?

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
