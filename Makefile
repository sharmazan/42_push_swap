NAME = push_swap
SRC_PATH = src
CC = cc
CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP_PATH = $(SRC_PATH)/$(NAME)
PUSH_SWAP_BIN = $(PUSH_SWAP_PATH)/$(NAME)
LIBFT_PATH = $(SRC_PATH)/libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
FTPRINTF_PATH = $(SRC_PATH)/ft_printf
FTPRINTF_LIB = $(FTPRINTF_PATH)/libftprintf.a
INC_PATH = $(SRC_PATH)/inc

PUSH_SWAP_SRCS = $(wildcard $(PUSH_SWAP_PATH)/*.c)
PUSH_SWAP_HDRS = $(wildcard $(INC_PATH)/*.h)
FTPRINTF_SRCS = $(wildcard $(FTPRINTF_PATH)/*.c)
FTPRINTF_HDRS = $(wildcard $(FTPRINTF_PATH)/*.h)
LIBFT_SRCS = $(wildcard $(LIBFT_PATH)/*.c)
LIBFT_HDRS = $(wildcard $(LIBFT_PATH)/*.h)

all: $(NAME)


$(NAME): $(PUSH_SWAP_BIN)
	cp $(PUSH_SWAP_BIN) $@

$(PUSH_SWAP_BIN): $(PUSH_SWAP_SRCS) $(PUSH_SWAP_HDRS) $(PUSH_SWAP_PATH)/Makefile $(FTPRINTF_LIB) $(LIBFT_LIB)
	$(MAKE) -C $(PUSH_SWAP_PATH) CC="$(CC)" CFLAGS="$(CFLAGS)"

$(FTPRINTF_LIB): $(FTPRINTF_SRCS) $(FTPRINTF_HDRS) $(FTPRINTF_PATH)/Makefile
	$(MAKE) -C $(FTPRINTF_PATH) CC="$(CC)" CFLAGS="$(CFLAGS)"

$(LIBFT_LIB): $(LIBFT_SRCS) $(LIBFT_HDRS) $(LIBFT_PATH)/Makefile
	$(MAKE) -C $(LIBFT_PATH) CC="$(CC)" CFLAGS="$(CFLAGS)"

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
