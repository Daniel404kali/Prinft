SOURCE_FILES = 	ft_putchar.c \
				ft_putstr.c \
				ft_strlen.c \
				ft_putnbr.c \
				ft_putnbr_base.c \
				ft_printf.c \
				ft_strchr.c 

BONUS_FILE = 	ft_flags.c \
				ft_itoa.c \
				ft_strlcpy.c \
				ft_letter.c 

OBJECTS = $(SOURCE_FILES:.c=.o)

OBJECTS_BONUS = $(BONUS_FILE:.c=.o)

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar -crs $@ $?

bonus: $(OBJECTS_BONUS)
	ar -crs $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJECTS)
	rm -rf $(OBJECTS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all