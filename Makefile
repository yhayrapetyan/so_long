SRC =	init_window.c \
		init_images.c \
		hook_operations.c \
		enemy_animation.c \
		create_map.c \
		init_map.c \
		main.c

VALIDATION_SRC = 	check_elements.c \
					check_for_double_new_line.c \
					is_map_playable.c \
					check_is_playable.c \
					check_is_rectangle.c \
					ft_error.c \
					is_ber.c \
					is_surrounded_by_walls.c

HELPERS_SRC = 	ft_itoa.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strjoin.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strtrim.c \
				ft_split.c \
				flood_fill.c

MOVEMENT_SRC = 	move_up.c \
				move_down.c \
				move_left.c \
				move_right.c

GNL_SRC = get_next_line.c \
		  get_next_line_utils.c

HEADERS = 	so_long.h \
			so_long_utils.h \
			get_next_line.h

SRC_DIR = ./src/game/
VALIDATION_DIR = ./src/validation/
HELPERS_DIR = ./src/helpers/
MOVEMENT_DIR = ./src/movement/
GNL_DIR = ./src/get_next_line/
INC = ./includes/

HEADERS := $(addprefix $(INC), $(HEADERS))
SRC := $(addprefix $(SRC_DIR), $(SRC))
GNL_SRC := $(addprefix $(GNL_DIR), $(GNL_SRC))
VALIDATION_SRC := $(addprefix $(VALIDATION_DIR), $(VALIDATION_SRC))
HELPERS_SRC := $(addprefix $(HELPERS_DIR), $(HELPERS_SRC))
MOVEMENT_SRC := $(addprefix $(MOVEMENT_DIR), $(MOVEMENT_SRC))
SRC += $(GNL_SRC)
SRC += $(VALIDATION_SRC)
SRC += $(HELPERS_SRC)
SRC += $(MOVEMENT_SRC)

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
RM = rm -f

UNAME = $(shell uname -s)

ifeq ($(UNAME),Darwin)
	LIB_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
else
	LIB_FLAGS = -L./mlx -lmlx -lXext -lX11 -lm -lbsd
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIB_FLAGS) -o $(NAME)

$(OBJS): $(HEADERS) Makefile

sanitize:
	cc  $(LIB_FLAGS) -fsanitize=address $(SRC) -o $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -I $(INC) -c  $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re sanitize bonus
