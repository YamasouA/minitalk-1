# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/30 23:12:52 by mmizuno           #+#    #+#              #
#    Updated: 2021/06/05 23:34:13 by mmizuno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================= Variable ================================= #

NAME				= minitalk

COMMON_INC_DIR		= ./include/
COMMON_SRC_DIR		= ./source/common/
COMMON_SRC_NAME		= print_message_common.c \
					  set_signal_common.c
COMMON_SRCS			= $(addprefix $(COMMON_SRC_DIR), $(COMMON_SRC_NAME))
COMMON_OBJS			= $(COMMON_SRCS:.c=.o)					  

CLIENT_NAME			= client
CLIENT_INC_DIR		= ./include/
CLIENT_SRC_DIR		= ./source/client/
CLIENT_SRC_NAME		= send_packet.c \
					  check_argument.c \
					  main.c
CLIENT_SRCS			= $(addprefix $(CLIENT_SRC_DIR), $(CLIENT_SRC_NAME))
CLIENT_OBJS			= $(CLIENT_SRCS:.c=.o)					  

SERVER_NAME			= server
SERVER_INC_DIR		= ./include/
SERVER_SRC_DIR		= ./source/server/
SERVER_SRC_NAME		= init_server_vars.c \
					  malloc_utility.c \
					  receive_packet.c \
					  print_message.c \
					  main.c
SERVER_SRCS			= $(addprefix $(SERVER_SRC_DIR), $(SERVER_SRC_NAME))
SERVER_OBJS			= $(SERVER_SRCS:.c=.o)					  

LIBFT_NAME			= libft.a
LIBFT_LIBNAME		= ft
LIBFT_DIR			= ./library/libft/
LIBFT_INC_DIR		= $(LIBFT_DIR)includes/

CC					= gcc
CFLAGS				= -Wall -Wextra -Werror #-g -fsanitize=address
INCDIR				= -I $(COMMON_INC_DIR)
INCDIR				+= -I $(CLIENT_INC_DIR)
INCDIR				+= -I $(SERVER_INC_DIR)
INCDIR				+= -I $(LIBFT_INC_DIR)
LIBDIR				= -L $(LIBFT_DIR)
LIBS				= -l $(LIBFT_LIBNAME)

RM					= rm -f

# ---------------------------------- color ----------------------------------- #

ESC_RESET			= \033[0m
ESC_FNT_BOLD		= \033[1m
ESC_FNT_FINE		= \033[2m
ESC_FNT_ITALIC		= \033[3m
ESC_FNT_ULINE		= \033[4m
ESC_CLR_BLACK		= \033[38;5;00m
ESC_CLR_RED			= \033[38;5;01m
ESC_CLR_GREEN		= \033[38;5;02m
ESC_CLR_YELLOW		= \033[38;5;03m
ESC_CLR_BLUE		= \033[38;5;04m
ESC_CLR_MAGENTA		= \033[38;5;05m
ESC_CLR_CYAN		= \033[38;5;06m
ESC_CLR_WHITE		= \033[38;5;07m
ESC_CLR_PINK		= \033[38;5;213m

# =============================== Make Command =============================== #

# ---------------------------------- .c.o ------------------------------------ #

.c.o:
					$(CC) $(CFLAGS) $(INCDIR) -c $< -o $(<:.c=.o)

# --------------------------------- $(NAME) ---------------------------------- #

$(NAME):
					@make $(LIBFT_NAME)
					@make $(CLIENT_NAME)
					@make $(SERVER_NAME)
					@echo "$(ESC_FNT_BOLD)$(ESC_CLR_GREEN)[ $(NAME) successfully compiled !! ]$(ESC_RESET)"

# --------------------------------- $(LIBFT) --------------------------------- #

$(LIBFT_NAME):
					@cd $(LIBFT_DIR) && make

# -------------------------------- $(CLIENT) --------------------------------- #

$(CLIENT_NAME):		$(COMMON_OBJS) $(CLIENT_OBJS)
					@make $(LIBFT_NAME)
					$(CC) $(CFLAGS) $(COMMON_OBJS) $(CLIENT_OBJS) $(LIBDIR) $(LIBS) -o $(CLIENT_NAME)
					@echo "$(ESC_FNT_BOLD)$(ESC_CLR_YELLOW)[ $(CLIENT_NAME) successfully compiled !! ]$(ESC_RESET)"

# -------------------------------- $(SERVER) --------------------------------- #

$(SERVER_NAME):		$(COMMON_OBJS) $(SERVER_OBJS)
					@make $(LIBFT_NAME)
					$(CC) $(CFLAGS) $(COMMON_OBJS) $(SERVER_OBJS) $(LIBDIR) $(LIBS) -o $(SERVER_NAME)
					@echo "$(ESC_FNT_BOLD)$(ESC_CLR_YELLOW)[ $(SERVER_NAME) successfully compiled !! ]$(ESC_RESET)"

# ----------------------------------- all ------------------------------------ #

all:				$(NAME)

# ---------------------------------- bonus ----------------------------------- #

bonus:				$(NAME)

# ---------------------------------- clean ----------------------------------- #

clean:
					@cd $(LIBFT_DIR) && make clean
					$(RM) $(COMMON_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS)

# ---------------------------------- fclean ---------------------------------- #

fclean:				clean
					@cd $(LIBFT_DIR) && make fclean
					$(RM) $(CLIENT_NAME)
					$(RM) $(SERVER_NAME)

# ------------------------------------ re ------------------------------------ #

re:					fclean all

# ---------------------------------- .PHONY ---------------------------------- #

.PHONY:				all bonus clean fclean re
