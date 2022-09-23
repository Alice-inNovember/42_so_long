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
#FILES
LIBS		=	$(LFTDIR)/libft.a \
				$(GNLDIR)/get_next_line.a \
				$(MLXDIR)/libmlx.a
SRCS		=	so_long.c
OBJS		=	${SRCS:.c=.o}
MAPSRCS		=	$(MAPDIR)/map_check.c \
				$(MAPDIR)/map_init_util.c
MAPOBJS		=	${MAPSRCS:.c=.o}

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(OBJS) $(MAPOBJS)
	$(MAKE) -C $(LFTDIR)
	$(MAKE) -C $(GNLDIR)
	$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MAPOBJS) $(LIBS) $(MLXFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LFTDIR) -I $(GNLDIR) -I $(MLXDIR) -I $(MAPDIR)

clean :
	$(MAKE) -C $(LFTDIR) clean
	$(MAKE) -C $(GNLDIR) clean
	$(MAKE) -C $(MLXDIR) clean
	$(RM) $(OBJS) $(MAPOBJS)

fclean : clean
	$(MAKE) -C $(LFTDIR) fclean
	$(MAKE) -C $(GNLDIR) fclean
	$(MAKE) -C $(MLXDIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re