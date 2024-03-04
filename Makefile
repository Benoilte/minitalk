# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 11:59:35 by bebrandt          #+#    #+#              #
#    Updated: 2024/03/04 14:21:55 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME		=	server

CLIENT_NAME		=	client

SRCS_DIR			=	srcs/

SERVER_SRCS		=	$(addsuffix .c, server)

CLIENT_SRCS		=	$(addsuffix .c, client)

SERVER_OBJ 		= $(SERVER_SRCS:.c=.o)

CLIENT_OBJ 		= $(CLIENT_SRCS:.c=.o)

SERVER_OBJS 	= $(addprefix $(OBJ_DIR),$(SERVER_OBJ))

CLIENT_OBJS 	= $(addprefix $(OBJ_DIR),$(CLIENT_OBJ))

LIBFT_DIR			=	libft/

LIBFT_NAME		=	libft.a

HDRS			=	-Iincludes/.

CC						=	gcc $(HDRS)

CFLAGS				=	-Wall -Wextra -Werror -g

RM						=	rm -f

OBJ_DIR				=	objs/


RED						=	\033[0;31m
GREEN					=	\033[0;32m
NONE					=	\033[0m

all: makelib $(SERVER_NAME) $(CLIENT_NAME)

makelib:
	@make -C $(LIBFT_DIR) all

$(SERVER_NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(CLIENT_NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(LIBFT_DIR)$(LIBFT_NAME):
	@make -C $(LIBFT_DIR) all

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)##### Creating" [ $@ ] " #####$(NONE)"
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(SERVER_OBJS)
	@rm -f $(CLIENT_OBJS)
	@echo "$(RED)##### Removed object files #####$(NONE)"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(SERVER_NAME)
	@rm -f $(CLIENT_NAME)
	@echo "$(RED)##### Removed binary files #####$(NONE)"

re: fclean all

.PHONY: makelib all clean fclean re
