SRC =	validation.c \
		ft_error.c \
		helpers.c \
		main.c \

BONUS_SRC = empty

OBJS = $(SRC:.c=.o)
HEADER = so_long.h
BONUS_OBJS = $(BONUS_SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
BONUS_NAME = checker
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJS): $(HEADER) Makefile
$(BONUS_OBJS): $(HEADER) Makefile

sanitize:
	cc -fsanitize=address $(SRC) -o $(NAME)

sanitize_bonus:
	cc -fsanitize=address $(BONUS_SRC) -o $(BONUS_NAME)


bonus: $(BONUS_OBJS) $(BONUS_NAME)

.c.o:
	@$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

.PHONY: all clean fclean re sanitize bonus
