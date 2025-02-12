NAME = libget_next_line.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = get_next_line.c get_next_line_utils.c

SRCB = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: .bonus

.bonus: $(OBJB)
	ar rcs $(NAME) $(OBJB)
	@touch .bonus

%.o : %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.c get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJB) .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re