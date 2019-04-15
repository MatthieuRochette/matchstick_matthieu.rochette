NAME	= matchstick

CC	= gcc

RM	= rm -f

SRCS	=	src/main.c				\
			src/error_management.c	\
			src/create_map.c		\
			src/update_game_board.c	\
			src/player_turn.c		\
			src/ai_turn.c			\
			src/utils.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -g -Iinclude -Llib -lmy
CFLAGS += -Wall -Wextra

all: $(NAME)
	$(RM) $(OBJS)

$(NAME): $(OBJS)
	cd lib/my/ && make re
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	rm -f lib/*.a
	rm -f lib/my/*.a

re: fclean all clean

.PHONY: all clean fclean re