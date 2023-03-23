NAME = fractol
SOURCES = test.c
PRINTF = ft_printf/ft_printf.a
OBJS = $(SOURCES:.c=.o)
INCLUDES = -I ft_printf/includes

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)	

$(NAME): $(PRINTF) $(OBJS)
# $(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(INCLUDES) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -Lminilibx-linux -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(PRINTF):
	make -C ft_printf

clean:
	make -C ft_printf clean
	$(RM) $(OBJS)

fclean: clean
	make -C ft_printf clean
	$(RM) $(NAME)

re: fclean $(NAME)