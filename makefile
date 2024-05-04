CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = fractol

SRCF = fractol.c ft_strcmp.c
OBJF = $(SRCF:.c=.o)

all: $(NAME)

$(NAME):$(OBJF)
	$(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit -o $@

%.o:%.c fractol.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJF) $(OBJBF)


fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:  clean