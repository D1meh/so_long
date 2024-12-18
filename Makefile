NAME	= 	so_long

CC = gcc

CFLAGS	= 	-Wall -Wextra -Werror

UTILS	=	basics/ft_strdup.c \
			basics/ft_strjoin.c \
			basics/ft_strlen.c \
			basics/ft_strstr.c \
			basics/ft_only1.c \
			basics/ft_split.c \
			basics/ft_splitlen.c \
			basics/ft_putsth.c \
			basics/ft_itoa.c \
			basics/ft_strchr.c 

U_OBJS	=	$(UTILS:.c=.o)

SRCS	=	so_long.c \
			utils/ft_parse.c \
			utils/open_n_close.c \
			utils/create_map.c \
			utils/create_huge.c \
			utils/controls.c \
			utils/interactions.c \
			utils/error.c

SRC_B	=	so_long_bonus.c \
			utils/error.c \
			bonus/ft_parse_bonus.c \
			bonus/open_n_close_bonus.c \
			bonus/create_map_bonus.c \
			bonus/create_huge_bonus.c \
			bonus/controls_bonus.c \
			bonus/interactions_bonus.c \
			bonus/enemies_bonus.c \
			bonus/animations_bonus.c

ifdef	OBJS_BONUS
	OBJS=$(SRC_B:.c=.o)
else
	OBJS=$(SRCS:.c=.o)
endif

all:		$(NAME)

$(NAME):	$(U_OBJS) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(U_OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus:		
		@make OBJS_BONUS=1 all

clean:
		rm -f $(OBJS) basics/*.o bonus/*.o so_long_bonus.o

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	clean fclean re bonus all