# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 11:59:35 by bebrandt          #+#    #+#              #
#    Updated: 2024/03/11 15:34:46 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME		=	server
SERVER_SRCS		=	$(addsuffix .c, server)
SERVER_OBJ 		= $(SERVER_SRCS:.c=.o)
SERVER_OBJS 	= $(addprefix $(OBJ_DIR),$(SERVER_OBJ))

CLIENT_NAME		=	client
CLIENT_SRCS		=	$(addsuffix .c, client client_signal_utils)
CLIENT_OBJ 		= $(CLIENT_SRCS:.c=.o)
CLIENT_OBJS 	= $(addprefix $(OBJ_DIR),$(CLIENT_OBJ))

SRCS_DIR		=	srcs/

LIBFT_DIR		=	libft/

LIBFT_NAME		=	libft.a

HDRS			=	-Iincludes/.

CC				=	gcc $(HDRS)

CFLAGS			=	-Wall -Wextra -Werror -g

RM				=	rm -f

OBJ_DIR			=	objs/

RED				=	\033[0;31m
GREEN			=	\033[0;32m
NONE			=	\033[0m

all: makelibs 
	@$(MAKE) $(SERVER_NAME)
	@$(MAKE) $(CLIENT_NAME)

bonus: all

makelibs:
	@make -C $(LIBFT_DIR) all

$(SERVER_NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(SERVER_OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)##### " $@ "Program is created #####$(NONE)"

$(CLIENT_NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)##### " $@ "Program is created #####$(NONE)"

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

.PHONY: makelibs bonus all clean fclean re
