CC = cc
CFLAGS = -Wall -Werror -Wextra

SOURCES = srcs
INCLUDES = includes
CFILES = $(addprefix $(SOURCES)/, main.c)
HFILES = $(addprefix $(INCLUDES)/, types.h)
OFILES = $(CFILES:.c=.o)

NAME = exchange-base

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES)

$(SOURCES)/%.o: $(SOURCES)/%.c $(HFILES)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
