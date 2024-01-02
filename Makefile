NAME	:= so_long
CFLAGS	:= -Wall -Wextra -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42

HEADERS	:= -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm -L/Users/$(USER)/.brew/Cellar/glfw/3.3.8/lib -lglfw

SRCS	:=	so_long.c \
			validate_map.c \
			route_validation.c \
			free_map.c \
			draw_map.c \
			captain_hook.c \
			move_player.c
			
OBJS	:= ${SRCS:.c=.o} libft/libft.a

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

libft/libft.a:
	@$(MAKE) -C libft/ all

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C libft/ clean

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx