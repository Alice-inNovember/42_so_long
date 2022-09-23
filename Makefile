NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
LIB_DIRS	=	get_next_line libmlx
LIBC 		=	ar rcs
LIBS		=	get_next_line.a libmlx.a
SRCS		=	
OBJS		=

all : $(NAME)

$(NAME) : $(OBJS) $(LIB_DIRS)
	$(CC) $(NAME) $(OBJS) -framework OpenGL -framework AppKit

bonus : $(NAME)

$(LIB_DIRS) :
	$(MAKE) -C $@

clean :
	for ldir in $(LIB_DIRS); do $(MAKE) -C $$ldir clean; done

fclean : clean
	for ldir in $(LIB_DIRS); do $(MAKE) -C $$ldir fclean; done

re : fclean all

.PHONY : all clean fclean re