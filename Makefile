# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 11:13:15 by tcaborde          #+#    #+#              #
#    Updated: 2022/12/09 16:16:02 by tcaborde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH		=	srcs/\

SRCS 		= so_long.c
			
NAME		= 	so_long

OBJS		=	$(addprefix .objects/, $(SRCS:.c=.o))

INCLUDES	=	includes/so_long.h

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

LIB			=	libft/libft.a

LFT			=	-L Libft -lft

RM			=	rm -rf

MLX			=	./mlx/

MLX_FLAGS	=	-L${MLX} -lmlx -framework OpenGL -framework Appkit $(LFT)

#COLORS
END=\033[0m
RED=\033[31m
GREEN=\033[32m
BLUE=\033[34m
ERASE=\033[2K\r
YELLOW = \033[1;33m

all:	mlx_lib lib $(NAME)

mlx_lib:
		make -C $(MLX)

lib:
		make -C libft

$(NAME): $(OBJS) $(INCLUDES) $(LIB) Makefile
		@$(CC) $(OBJS) ${CFLAG} $(MLX_FLAGS) -I includes -o $@
		@echo "$(ERASE)$(GREEN)[CREATE $(NAME)]$(END)" 

.objects/%.o: %.c Makefile $(INCLUDES)
		@mkdir -p .objects
		@$(CC) $(CFLAGS) -I${MLX} -I includes -c $< -o $@
		@printf "$(ERASE)$(BLUE)[BUILDING]$(END) $@"

clean:
		@${RM} ${OBJS}
		@make fclean -C libft
		@echo "${RED}[DELETED SO_LONG OBJS]${END}"

fclean: clean
		@${RM} ${NAME}
		@${RM} .objects
		@echo "${RED}[DELETED]${END} ${NAME}"

re: fclean all

.PHONY: all clean re fclean 