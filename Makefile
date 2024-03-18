SRC =	init_window.c \
		init_images.c \
		hook_operations.c \
		enemy_animation.c \
		create_map.c \
		init_map.c \
		end_game.c \
		main.c \

VALIDATION_SRC = 	check_elements.c \
					check_for_double_new_line.c \
					is_map_playable.c \
					check_is_playable.c \
					check_is_rectangle.c \
					ft_error.c \
					is_ber.c \
					is_surrounded_by_walls.c \
					is_larger_than_screen.c

HELPERS_SRC = 	ft_itoa.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strjoin.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strtrim.c \
				ft_split.c \
				flood_fill.c \
				ft_strdup.c \
				ft_strtrim_end.c

MOVEMENT_SRC = 	movement_utils.c \
				move_to.c

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

BLUE   = \033[0;34m
GREEN    = \033[0;32m
RED = \033[0;31m
YELLOW  = \033[0;33m
NO_COLOR    = \033[m

UNAME = $(shell uname -s)

ifeq ($(UNAME),Darwin)
	LIB_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
else
	LIB_FLAGS = -L./mlx -lmlx -lXext -lX11 -lm -lbsd
endif

SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

all: print_info $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIB_FLAGS) -o $(NAME)
	@printf "%b" "$(BLUE)\n$@ $(GREEN)[✓]\n"

$(OBJS): $(HEADERS) Makefile

sanitize: $(OBJS)
	@cc $(OBJS) $(LIB_FLAGS) -fsanitize=address  -o $(NAME)

.c.o:
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@printf "\r%18s\r$(YELLOW)[ %d/%d (%d%%) ]$(NO_COLOR)" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -I $(INC) -c  $< -o $(<:.c=.o)

clean: print_name
	@$(RM) $(OBJS)
	@printf "%b" "$(BLUE)$@: $(GREEN)[✓]\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "%b" "$(BLUE)$@: $(GREEN)[✓]\n"

re: fclean all
	@printf "%b" "$(BLUE)$@: $(GREEN)[✓]\n"

print_info: print_name
	@printf "%b" "$(BLUE)Compiler: $(GREEN)$(CC)\n"
	@printf "%b" "$(BLUE)Name: $(GREEN)$(NAME)\n"
	@printf "%b" "$(BLUE)Uname: $(GREEN)$(UNAME)\n"
	@printf "%b" "$(BLUE)C Flags: $(GREEN)$(CFLAGS)\n"
	@printf "%b" "$(BLUE)Lib Flags: $(GREEN)$(LIB_FLAGS)\n"
	@printf "%b" "$(BLUE)Src Count: $(GREEN)$(SRC_COUNT_TOT)\n"


print_name:
	@printf "%b" "$(BLUE)"
	@echo "   _____  ____          _      ____  _   _  _____ "
	@echo "  / ____|/ __ \        | |    / __ \| \ | |/ ____|"
	@echo " | (___ | |  | |       | |   | |  | |  \| | |  __ "
	@echo "  \___ \| |  | |       | |   | |  | | . \` | | |_ |"
	@echo "  ____) | |__| |       | |___| |__| | |\  | |__| |"
	@echo " |_____/ \____/        |______\____/|_| \_|\_____|"
	@echo "\n"

.PHONY: all clean fclean re sanitize bonus print_name print_info
