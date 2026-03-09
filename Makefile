NAME = push_swap
SRC_PATH = src
CC = cc
CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP_PATH = $(SRC_PATH)/$(NAME)
LIBFT_PATH = $(SRC_PATH)/libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
FTPRINTF_PATH = $(SRC_PATH)/ft_printf
FTPRINTF_LIB = $(FTPRINTF_PATH)/libftprintf.a
HEADER = src/inc/ft_header.h

PUSH_SWAP_SOURCES = $(PUSH_SWAP_PATH)/push_swap.c
PUSH_SWAP_OBJECTS = $(PUSH_SWAP_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(FTPRINTF_LIB) $(LIBFT_LIB) $(PUSH_SWAP_OBJECTS) $(HEADER)
	$(MAKE) -C $(PUSH_SWAP_PATH) CC="$(CC)" CFLAGS="$(CFLAGS)"
	cp $(PUSH_SWAP_PATH)/$(NAME) .

$(FTPRINTF_LIB):
	$(MAKE) -C $(FTPRINTF_PATH) CC="$(CC)" CFLAGS="$(CFLAGS)"

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_PATH) CC="$(CC)" CFLAGS="$(CFLAGS)"

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

debug: CFLAGS += -g3 -O0
debug: re

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(FTPRINTF_PATH) fclean
	$(MAKE) -C $(PUSH_SWAP_PATH) fclean

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(FTPRINTF_PATH) clean
	$(MAKE) -C $(PUSH_SWAP_PATH) clean

re: fclean all

.PHONY: all clean tests re fclean debug
