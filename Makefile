# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 11:40:41 by mmizuno           #+#    #+#              #
#    Updated: 2021/06/04 22:13:20 by mmizuno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================= Variable ================================= #

NAME				= libft.a
NAME_DYNAMIC		= libft.so

PRJDIR				= ./
INCDIR				= $(PRJDIR)includes/
SRCDIR				= $(PRJDIR)sources/

MANDATORY_INCDIR	= $(INCDIR)
MANDATORY_SRCDIR	= $(SRCDIR)mandatory/
MANDATORY_SRCNAME	= ft_memset.c \
					  ft_bzero.c \
					  ft_memcpy.c \
					  ft_memccpy.c \
					  ft_memmove.c \
					  ft_memchr.c \
					  ft_memcmp.c \
					  ft_strlen.c \
					  ft_strlcpy.c \
					  ft_strlcat.c \
					  ft_strchr.c \
					  ft_strrchr.c \
					  ft_strnstr.c \
					  ft_strncmp.c \
					  ft_atoi.c \
					  ft_isalpha.c \
					  ft_isdigit.c \
					  ft_isalnum.c \
					  ft_isascii.c \
					  ft_isprint.c \
					  ft_toupper.c \
					  ft_tolower.c \
					  ft_calloc.c \
					  ft_strdup.c \
					  ft_substr.c \
					  ft_strjoin.c \
					  ft_strtrim.c \
					  ft_split.c \
					  ft_itoa.c \
					  ft_strmapi.c \
					  ft_putchar_fd.c \
					  ft_putstr_fd.c \
					  ft_putendl_fd.c \
					  ft_putnbr_fd.c
MANDATORY_SRCS		= $(addprefix $(MANDATORY_SRCDIR), $(MANDATORY_SRCNAME))
MANDATORY_OBJS		= $(MANDATORY_SRCS:.c=.o)

BONUS_INCDIR		= $(INCDIR)
BONUS_SRCDIR		= $(SRCDIR)bonus/
BONUS_SRCNAME		= ft_lstnew.c \
					  ft_lstadd_front.c \
					  ft_lstsize.c \
					  ft_lstlast.c \
					  ft_lstadd_back.c \
					  ft_lstdelone.c \
					  ft_lstclear.c \
					  ft_lstiter.c \
					  ft_lstmap.c
BONUS_SRCS			= $(addprefix $(BONUS_SRCDIR), $(BONUS_SRCNAME))
BONUS_OBJS			= $(BONUS_SRCS:.c=.o)

EXTRA_INCDIR		= $(INCDIR)
EXTRA_SRCDIR		= $(SRCDIR)extra/
EXTRA_SRCNAME		= ft_iscntrl.c \
					  ft_isgraph.c \
					  ft_islower.c \
					  ft_ispunct.c \
					  ft_isspace.c \
					  ft_isupper.c \
					  ft_isxdigit.c \
					  ft_isblank.c \
					  ft_strpbrk.c \
					  ft_lstpush_front.c \
					  ft_lstpush_back.c \
					  ft_lstpush_strs.c \
					  ft_lstat.c \
					  ft_lstreverse.c \
					  ft_lstiter_if.c \
					  ft_lstfind.c \
					  ft_lstremove_if.c \
					  ft_lstmerge.c \
					  ft_lstsort.c \
					  ft_lstreverse_fun.c \
					  ft_lstsorted_insert.c \
					  ft_lstsorted_merge.c \
					  btree_create_node.c \
					  btree_apply_prefix.c \
					  btree_apply_infix.c \
					  btree_apply_suffix.c \
					  btree_insert_data.c \
					  btree_search_item.c \
					  btree_level_count.c \
					  ft_trim_left.c \
					  ft_trim_right.c \
					  ft_trim.c
EXTRA_SRCS			= $(addprefix $(EXTRA_SRCDIR), $(EXTRA_SRCNAME))
EXTRA_OBJS			= $(EXTRA_SRCS:.c=.o)

CC					= gcc
CFLAGS				= -Wall -Wextra -Werror #-g -fsanitize=address

AR					= ar
ARFLAGS				= rcs

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
					$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $(<:.c=.o)

# --------------------------------- $(NAME) ---------------------------------- #

$(NAME):			$(MANDATORY_OBJS) $(BONUS_OBJS) $(EXTRA_OBJS)
					$(AR) $(ARFLAGS) $(NAME) $(MANDATORY_OBJS) $(BONUS_OBJS) $(EXTRA_OBJS)
					@echo "$(ESC_FNT_BOLD)$(ESC_CLR_GREEN)[ $(NAME) successfully compiled !! ]$(ESC_RESET)"

# ----------------------------------- all ------------------------------------ #

all: 				$(NAME)

# -------------------------------- mandatory --------------------------------- #

mandatory:			$(MANDATORY_OBJS)
					$(AR) $(ARFLAGS) $(NAME) $(MANDATORY_OBJS)
					@echo "$(ESC_FNT_BOLD)$(ESC_CLR_GREEN)[ $(NAME) successfully compiled !! ]$(ESC_RESET)"

# ---------------------------------- bonus ----------------------------------- #

bonus:				$(MANDATORY_OBJS) $(BONUS_OBJS)
					$(AR) $(ARFLAGS) $(NAME) $(MANDATORY_OBJS) $(BONUS_OBJS)
					@echo "$(ESC_FNT_BOLD)$(ESC_CLR_GREEN)[ $(NAME) successfully compiled !! ]$(ESC_RESET)"

# ---------------------------------- clean ----------------------------------- #

clean:
					$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS) $(EXTRA_OBJS)

# ---------------------------------- fclean ---------------------------------- #

fclean:				clean
					$(RM) $(NAME)
					$(RM) $(NAME_DYNAMIC)

# ------------------------------------ re ------------------------------------ #

re:					fclean all

# ------------------------------------ so ------------------------------------ #

so:					$(MANDATORY_OBJS) $(BONUS_OBJS) $(EXTRA_OBJS)
					$(CC) $(CFLAGS) -I $(INCDIR) -shared -fPIC -o $(NAME_DYNAMIC) $(MANDATORY_SRCS) $(BONUS_SRCS) $(EXTRA_SRCS)
					@echo "$(ESC_FNT_BOLD)$(ESC_CLR_GREEN)[ $(NAME_DYNAMIC) successfully compiled !! ]$(ESC_RESET)"

# ---------------------------------- .PHONY ---------------------------------- #

.PHONY:				all mandatory bonus clean fclean re so
