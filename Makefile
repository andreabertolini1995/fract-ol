NAME = fractol
# SOURCES = test.c
SOURCES = main.c fractals_math.c
FT_PRINTF = ft_printf/ft_printf.a
LIBFT = libft/libft.a
MLX42 = MLX42/build/libmlx42.a
OBJS = $(SOURCES:.c=.o)
INCLUDES = -I ft_printf/includes -I libft/includes -I MLX42/include

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -ldl -lglfw -pthread -lm

all: $(NAME)	

$(NAME): $(FT_PRINTF) $(MLX42) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX42) $(MLXFLAGS) $(INCLUDES) -o $(NAME)
# MACOS
# $(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX42) $(MLXFLAGS) $(INCLUDES) -o $(NAME) -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"

$(LIBFT):
	make -C libft

$(FT_PRINTF):
	make -C ft_printf

$(MLX42):
	make -C MLX42

clean:
	make -C libft clean
	make -C ft_printf clean
	$(RM) $(OBJS)

fclean: clean
	make -C libft clean
	make -C ft_printf clean
	$(RM) $(NAME)

re: fclean $(NAME)