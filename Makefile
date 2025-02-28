SRC = ./mandatory/so_long.c ./mandatory/so_long_utils.c ./mandatory/so_long_utils2.c ./mandatory/draw.c ./mandatory/movements.c
SRCBonus = ./bonus/so_long_bonus.c ./bonus/so_long_utils_bonus.c ./bonus/so_long_utils2_bonus.c ./bonus/draw_bonus.c ./bonus/movements_bonus.c ./bonus/enemy_bonus.c
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
libraries = ./ft_printf/libftprintf.a ./get_next_line/libget_next_line.a ./libft/libft.a
SUBDIRS = get_next_line ft_printf libft

.SILENT:

all: libs $(NAME)
	@echo "\033[104mThe mandatory part is made\033[0m"

$(NAME): $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(libraries) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

libs: $(SUBDIRS)
	@echo "\033[1;32mmaking the libs ...\033[0m"
	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir) all;)
	@echo "\033[1;31mit's made \033[0m"

libsre: $(SUBDIRS)
	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir) re;)

libsclean: $(SUBDIRS)
	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir) fclean;)

clean: $(SUBDIRS)
	@echo "\033[1;32mcleaning the objects \033[0m"
	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir) clean;)

bonus: libs $(SRCBonus)
	@echo "\033[1;32mWork is done !\033[0m"
	@echo "\033[104mBonus is\033[0m \033[1;32mready !!!\033[0m ?"
	$(CC) $(SRCBonus) $(CFLAGS) $(libraries) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

fclean:
	$(RM) $(NAME)
	@echo "\033[1;32mremoving So_long file \033[0m"

re: fclean libsclean all