NAME = ft_printf.a

SOURCES = ft_printf.c ft_puthex_count_int.c ft_puthex_count_ulong.c ft_put.c ft_strlen.c ft_strncmp.c ft_utils.c

OBJS = $(SOURCES:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)	

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
