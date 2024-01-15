CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit
# MLXFLAGS = -lX11 -lXext
MATHFLAGS = -lm
SRCS = drawing_utils.c string_utils.c fractol.c ft_atof.c math_utils.c mlx_utils.c
HFILE = fractol.h
OBJS = ${SRCS:.c=.o}
NAME = fractol
LIBMLX = mlx/libmlx.a


all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX) $(HFILE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBMLX) $(MLXFLAGS) $(MATHFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBMLX):
	make all -C mlx

clean:
	rm -rf $(OBJS) $(LIBMLX)
	make clean -C mlx

fclean: clean
	rm -rf $(NAME)

re: fclean all