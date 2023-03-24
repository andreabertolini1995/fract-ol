NAME = fractol
SOURCES = main.c
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
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(MLX42) $(MLXFLAGS) $(INCLUDES) -o $(NAME)

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