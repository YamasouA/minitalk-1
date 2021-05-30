# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/30 23:12:52 by mmizuno           #+#    #+#              #
#    Updated: 2021/05/30 23:20:55 by mmizuno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================= Variable ================================= #

NAME				= minitalk

CLIENT_NAME			= client
CLIENT_INC_DIR		= ./include/
CLIENT_SRC_DIR		= ./source/client/
CLIENT_SRC_NAME		= print_error.c \
					  main.c
CLIENT_SRCS			= $(addprefix $(CLIENT_SRC_DIR), $(CLIENT_SRC_NAME))
CLIENT_OBJS			= $(CLIENT_SRCS:.c=.o)					  

SERVER_NAME			= server
SERVER_INC_DIR		= ./include/
SERVER_SRC_DIR		= ./source/server/
SERVER_SRC_NAME		= print_error.c \
					  main.c
SERVER_SRCS			= $(addprefix $(SERVER_SRC_DIR), $(SERVER_SRC_NAME))
SERVER_OBJS			= $(SERVER_SRCS:.c=.o)					  

LIBFT_NAME			= libft.a
LIBFT_LIBNAME		= ft
LIBFT_DIR			= ./library/libft/
LIBFT_INC_DIR		= $(LIBFT_DIR)includes/

CC					= gcc
CFLAGS				= -Wall -Wextra -Werror #-g -fsanitize=address
INCDIR				= -I $(CLIENT_INC_DIR) -I $(SERVER_INC_DIR) -I $(LIBFT_INC_DIR)
LIBDIR				= -L $(LIBFT_DIR)
LIBS				= -l $(LIBFT_LIBNAME)

RM					= rm -f

# ---------------------------------- color ----------------------------------- #

ESC_CLR_RESET		= \033[00m
ESC_CLR_BLACK		= \033[30m
ESC_CLR_RED			= \033[31m
ESC_CLR_GREEN		= \033[32m
ESC_CLR_YELLOW		= \033[33m
ESC_CLR_BLUE		= \033[34m
ESC_CLR_MAGENTA		= \033[35m
ESC_CLR_CYAN		= \033[36m
ESC_CLR_WHITE		= \033[37m

# =============================== Make Command =============================== #

# ---------------------------------- .c.o ------------------------------------ #

.c.o:
					$(CC) $(CFLAGS) $(INCDIR) -c $< -o $(<:.c=.o)

# --------------------------------- $(NAME) ---------------------------------- #

$(NAME):			$(LIBFT_NAME) $(CLIENT_NAME) $(SERVER_NAME)
					@echo "$(ESC_CLR_GREEN)"
					@echo "[ (NAME) successfully compiled!! ]"
					@echo "$(ESC_CLR_RESET)"

# --------------------------------- $(LIBFT) --------------------------------- #

$(LIBFT_NAME):
					@cd $(LIBFT_DIR) && make re
					@cd $(LIBFT_DIR) && make clean
					@echo "$(ESC_CLR_YELLOW)"
					@echo "[ $(LIBFT_NAME) successfully compiled!! ]"
					@echo "$(ESC_CLR_RESET)"

# -------------------------------- $(CLIENT) --------------------------------- #

$(CLIENT_NAME):		$(CLIENT_OBJS)
					$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBDIR) $(LIBS) -o $(NAME)
					@echo "$(ESC_CLR_YELLOW)"
					@echo "[ $(CLIENT_NAME) successfully compiled!! ]"
					@echo "$(ESC_CLR_RESET)"

# -------------------------------- $(SERVER) --------------------------------- #

$(SERVER_NAME):		$(SERVER_OBJS)
					$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBDIR) $(LIBS) -o $(NAME)
					@echo "$(ESC_CLR_YELLOW)"
					@echo "[ $(SERVER_NAME) successfully compiled!! ]"
					@echo "$(ESC_CLR_RESET)"

# ----------------------------------- all ------------------------------------ #

all:				$(NAME)

# ---------------------------------- bonus ----------------------------------- #

bonus:				$(NAME)

# ---------------------------------- clean ----------------------------------- #

clean:
					$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

# ---------------------------------- fclean ---------------------------------- #

fclean:				clean
					$(RM) $(NAME)
					$(RM) $(LIBFT_DIR)$(LIBFT_NAME)

# ------------------------------------ re ------------------------------------ #

re:					fclean all

# ---------------------------------- .PHONY ---------------------------------- #

.PHONY:				all bonus clean fclean re
