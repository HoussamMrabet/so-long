NAME = so_long

BONUS = so_long_bonus

SRCS = main.c moves.c draw.c parser-0.c parser-1.c protect.c get_next_line.c get_next_line_utils.c

BSRCS = main_bonus.c moves_bonus.c draw_bonus.c parser-0_bonus.c parser-1_bonus.c protect_bonus.c init_images_bonus.c coin_flip_bonus.c game_over_bonus.c get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

CC = @cc -Wall -Wextra -Werror
INCLUDES = -Imlx -Ilibft
LIB = -Llibft -lft
LIBFT = libft
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

RED = \033[1;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
RESET = \033[0m

all : $(LIBFT) $(NAME)

bonus : $(LIBFT) $(BONUS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) $(LIB) -o $(NAME)
	@echo "$(GREEN)so_long created! ✅$(RESET)"

$(BONUS): $(BOBJS)
	$(CC) $(BOBJS) $(MLX_FLAGS) $(LIB) -o $(BONUS)
	@echo "$(GREEN)so_long_bonus created! ✅$(RESET)"

$(LIBFT) :
	@make -C libft


%.o: %.c get_next_line.h so_long.h so_long_bonus.h libft/libft.a
	$(CC) $(INCLUDES) -c $< -o $@

clean :
	@make clean -C libft
	@rm -f $(OBJS) $(BOBJS)
	@echo "$(YELLOW)cleaning objects! 🧹✨$(RESET)"

fclean :
	@make fclean -C libft
	@rm -f $(OBJS) $(BOBJS)
	@rm -f $(NAME) $(BONUS)
	@echo "$(RED)so_long removed! ❌$(RESET)"

re : fclean all

.PHONY : clean fclean $(LIBFT)
