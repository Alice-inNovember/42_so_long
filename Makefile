#NAME
NAME		=	so_long
#CMDS
CC			=	gcc
RM			=	rm -rf
LIBC		=	ar rcs
#FLAGS
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-framework OpenGL -framework AppKit
#DIRS
LFTDIR		=	libft
GNLDIR		=	get_next_line
MLXDIR		=	libmlx
#FILES
LIBS		=	$(LFTDIR)/libft.a \
				$(GNLDIR)/get_next_line.a
DYLIB		=	$(MLXDIR)/libmlx.dylib
SRCS		=	so_long.c \
				so_long_util.c \
				so_display.c \
				so_map_check.c \
				so_map_init.c \
				so_sprite_init.c
OBJS		=	${SRCS:.c=.o}

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(OBJS) $(MAPOBJS) $(SPRITEOBJS)
	$(MAKE) -C $(LFTDIR)
	$(MAKE) -C $(GNLDIR)
	$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(MLXFLAGS) -L$(MLXDIR) -lmlx
	-install_name_tool -change libmlx.dylib ./$(DYLIB) $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LFTDIR) -I $(GNLDIR) -I $(MLXDIR) -I $(PWD)

clean :
	$(MAKE) -C $(LFTDIR) clean
	$(MAKE) -C $(GNLDIR) clean
	$(MAKE) -C $(MLXDIR) clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C $(LFTDIR) fclean
	$(MAKE) -C $(GNLDIR) fclean
	$(MAKE) -C $(MLXDIR) clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re