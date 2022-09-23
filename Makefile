NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-framework OpenGL -framework AppKit
RM			=	rm -rf
LIBC		=	ar rcs
GNLDIR		=	get_next_line
GNLLIB		=	get_next_line/libget_next_line.a
MLXDIR		=	libmlx
MLXLIB		=	libmlx/libmlx.a
SRCS		=	main.c
OBJS		=	${SRCS:.c=.o}

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C get_next_line
	$(MAKE) -C libmlx
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(GNLLIB) $(MLXLIB) $(MFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(GNLDIR) -I $(MLXDIR)

clean :
	$(MAKE) -C get_next_line clean
	$(MAKE) -C libmlx clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C get_next_line fclean
	$(MAKE) -C libmlx fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re