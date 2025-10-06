# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gluz-ste <gluz-ste@student.42luxembou      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 14:51:26 by gluz-ste          #+#    #+#              #
#    Updated: 2025/10/06 14:51:29 by gluz-ste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O2
MATH		= -lm
MLX_PATH	= minilibx-linux/
MLX_LIB		= $(MLX_PATH)libmlx.a
MLX_FLAGS	= $(MLX_LIB) -L/usr/lib/X11 -lXext -lX11


SRCDIR		= src/
OBJDIR		= obj/
INC		= -Iincludes -I$(MLX_PATH)

SOURCES		= fractol.c \
			  init.c \
			  render.c \
			  events.c \
			  math_utils.c \
			  color_utils.c \
			  string_utils.c \
			  equations.c

OBJECTS		= $(SOURCES:%.c=$(OBJDIR)%.o)

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJDIR) $(OBJECTS) $(MLX_LIB)
	$(CC) $(OBJECTS) $(MLX_FLAGS) $(MATH) -o $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH) -f Makefile.mk INC=/usr/include all

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(MLX_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
