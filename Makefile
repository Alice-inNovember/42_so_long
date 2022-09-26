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
MAPDIR		=	map_srcs
SPRDIR		=	sprite_srcs
#FILES
LIBS		=	$(LFTDIR)/libft.a \
				$(GNLDIR)/get_next_line.a
DYLIB		=	$(MLXDIR)/libmlx.dylib
SRCS		=	so_long.c
OBJS		=	${SRCS:.c=.o}
MAPSRCS		=	$(MAPDIR)/map_check.c \
				$(MAPDIR)/map_init_util.c
MAPOBJS		=	${MAPSRCS:.c=.o}
SPRITESRCS	=	$(SPRDIR)/sprite_init.c
SPRITEOBJS	=	${SPRITESRCS:.c=.o}

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(OBJS) $(MAPOBJS) $(SPRITEOBJS)
	$(MAKE) -C $(LFTDIR)
	$(MAKE) -C $(GNLDIR)
	$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MAPOBJS) $(SPRITEOBJS) $(LIBS) $(MLXFLAGS) -L$(MLXDIR) -lmlx
	-install_name_tool -change libmlx.dylib ./$(DYLIB) $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LFTDIR) -I $(GNLDIR) -I $(MLXDIR) -I $(MAPDIR) -I $(SPRDIR)

clean :
	$(MAKE) -C $(LFTDIR) clean
	$(MAKE) -C $(GNLDIR) clean
	$(MAKE) -C $(MLXDIR) clean
	$(RM) $(OBJS) $(MAPOBJS) $(SPRITEOBJS)

fclean : clean
	$(MAKE) -C $(LFTDIR) fclean
	$(MAKE) -C $(GNLDIR) fclean
	$(MAKE) -C $(MLXDIR) clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re