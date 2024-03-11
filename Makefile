SRC =	validation.c \
		ft_split.c \
		init_map.c \
		ft_error.c \
		helpers.c \
		main.c \

GNL_SRC = get_next_line.c \
		  get_next_line_utils.c
GNL_SRC := $(addprefix get_next_line/, $(GNL_SRC))

SRC += $(GNL_SRC)

BONUS_SRC = empty

OBJS = $(SRC:.c=.o)
HEADER = so_long.h
BONUS_OBJS = $(BONUS_SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
BONUS_NAME = checker
RM = rm -f

UNAME = $(shell uname -s)

ifeq ($(UNAME),Darwin)
	LIB_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
else
	LIB_FLAGS = -L./mlx -lmlx -lXext -lX11 -lm -lbsd
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIB_FLAGS) -o $(NAME)

$(OBJS): $(HEADER) Makefile
$(BONUS_OBJS): $(HEADER) Makefile

sanitize:
	cc  $(LIB_FLAGS) -fsanitize=address $(SRC) -o $(NAME)

sanitize_bonus:
	cc -fsanitize=address $(BONUS_SRC) -o $(BONUS_NAME)


bonus: $(BONUS_OBJS) $(BONUS_NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

.PHONY: all clean fclean re sanitize bonus
