CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS_LEAKS = -fcolor-diagnostics -fansi-escape-codes -fsanitize=address

SRCS = srcs
INCLUDES = includes

CFILES = $(addprefix $(SRCS)/, main.c uniqid.c file.c stds.c)
HFILES = $(addprefix $(INCLUDES)/, types.h uniqid.h file.h stds.h)
OFILES = $(CFILES:%.c=%.o)


NAME = exchange.out

all: $(NAME)

$(NAME): $(OFILES) $(LIBS)
	$(CC) $(CFLAGS) -o $@ $(OFILES) $(LIBS)

%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCLUDES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

leaks: fclean $(OFILES)
	@clear
	@echo "leak build"
	$(CC) $(CFLAGS) $(CFLAGS_LEAKS) -o $(NAME) $(OFILES)
	@clear
	@./$(NAME)

.PHONY: all clean fclean re libs leaks
