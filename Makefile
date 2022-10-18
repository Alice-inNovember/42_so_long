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
SRCDIR		=	so_srcs
BONUSDIR	=	so_bonus
#FILES
LIBS		=	$(LFTDIR)/libft.a \
				$(GNLDIR)/get_next_line.a
DYLIB		=	$(MLXDIR)/libmlx.dylib
SRCS		=	$(SRCDIR)/so_long.c $(SRCDIR)/so_long_util.c \
				$(SRCDIR)/so_display.c $(SRCDIR)/so_display_score.c \
				$(SRCDIR)/so_map_init.c $(SRCDIR)/so_map_check.c \
				$(SRCDIR)/so_sprite_init.c $(SRCDIR)/so_sprite_init2.c \
				$(SRCDIR)/so_player_control.c $(SRCDIR)/so_mob_control.c
OBJS		=	${SRCS:.c=.o}
BSRCS		=	$(BONUSDIR)/so_long_bonus.c $(BONUSDIR)/so_long_util_bonus.c \
				$(BONUSDIR)/so_display_bonus.c $(BONUSDIR)/so_display_score_bonus.c \
				$(BONUSDIR)/so_map_init_bonus.c $(BONUSDIR)/so_map_check_bonus.c \
				$(BONUSDIR)/so_sprite_init_bonus.c $(BONUSDIR)/so_sprite_init2_bonus.c \
				$(BONUSDIR)/so_player_control_bonus.c $(BONUSDIR)/so_mob_control_bonus.c
BOBJS		=	${BSRCS:.c=.o}

all : $(NAME)

ifeq ($(filter bonus, $(MAKECMDGOALS)), bonus)
$(NAME) : $(BOBJS)
	$(MAKE) -C $(LFTDIR)
	$(MAKE) -C $(GNLDIR)
	$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(BOBJS) $(LIBS) $(MLXFLAGS) -L$(MLXDIR) -lmlx
	-install_name_tool -change libmlx.dylib ./$(DYLIB) $(NAME)
else
$(NAME) : $(OBJS)
	$(MAKE) -C $(LFTDIR)
	$(MAKE) -C $(GNLDIR)
	$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(MLXFLAGS) -L$(MLXDIR) -lmlx
	-install_name_tool -change libmlx.dylib ./$(DYLIB) $(NAME)
endif

bonus : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LFTDIR) -I $(GNLDIR) -I $(MLXDIR)

clean :
	$(MAKE) -C $(LFTDIR) clean
	$(MAKE) -C $(GNLDIR) clean
	$(MAKE) -C $(MLXDIR) clean
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(MAKE) -C $(LFTDIR) fclean
	$(MAKE) -C $(GNLDIR) fclean
	$(MAKE) -C $(MLXDIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re