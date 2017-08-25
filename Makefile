# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdube <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 18:31:07 by sdube             #+#    #+#              #
#    Updated: 2016/11/03 18:35:47 by sdube            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  ft_camera.c ft_objects_base.c\
	  manager/app_environ.c\
	  manager/window.c\
	  vector/ft_vector.c \
	  vector/ft_vector_ops.c \
	  vector/ft_vector_arithmetic.c \
	  ft_color.c ft_objects.c ft_ray.c ft_stack.c \
	  utils.c\
	  engine/operations.c \
	  engine/shading_model.c \
	  engine/core.c \
	  engine/intersections.c \
	  engine/ft_normals.c \
	  engine/engine_utils.c \
	  matrix/ft_matrix.c \
	  matrix/ft_matrix_ops.c \
	  matrix/matrix_utils.c\
	  matrix/garbage_collector.c\
	  matrix/matrix_ops2.c\
	  matrix/matrix_utils_2.c\
	  matrix/transformation_matrices.c\
	  imod/imod.c\
	  imod/process_values.c\
	  imod/ezxml_utils.c\
	  imod/get_vector.c\
	  imod/interface.c\
	  imod/ft_atodouble.c\

NAME = RTv1

ARGS = -Wall -Werror -Wextra -g -O3

INC = -I. -I/usr/include/X11 -Iincludes/ -Ilibft/ -Ivector -Imatrix/

LIXLIB = -lXext -lX11

MACLIB = -framework OpenGL -framework AppKit -lm

LIBS = -Llibft -lft -Limod/ezxml -lezxml -lmlx -lm

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(DEBUG): $(ARGS)

%.o: %.c
	@echo "\033[33m$^\033[0m changed.\nRecompiling..."
	@gcc $(ARGS) -c -o $@ $^ $(INC)
	@echo "\033[33m$^\033[0m Compiled."
$(NAME): $(OBJ)
ifeq ($(shell, uname), Linux)
	@make -s -C imod/ezxml clean all
	@make -s -C libft/ 
	@gcc $(ARGS) $(INC) $(SRC) $(LIXLIB) $(LIBS) -o $(NAME)
else
	@make -s -C imod/ezxml clean all
	@make -s -C libft/ 
	@gcc $(ARGS) $(INC) $(SRC) $(MACLIB) $(LIBS) -o $(NAME)
endif
clean:
	@make -s -C imod/ezxml clean
	@make -s -C libft/ clean
	@rm -f $(NAME)
	@rm -f *.o
	@rm -f vector/*.o
	@rm -f imod/*.o
	@rm -f engine/*.o
	@rm -f manager/*.o
	@rm -f matrix/*.o

fclean: clean
	@make -C libft/ fclean

re: fclean all
