RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RESET	= \033[0;37m
SKY		= \033[1;36m

NAME = libft.a
CC = cc
# -Wall -Wextra -Werror
CFLAGS = -g -Wall -Wextra -Werror -c 
ROOT = ./

MANDATORY		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
				ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
				ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_putstr_fd.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c  \
				ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_strlen.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
				ft_safe_malloc.c ft_err.c ft_strstr.c ft_str_ends_with.c ft_str_contains.c ft_isspace.c

OBJS = $(MANDATORY:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@ar -rcs $@ $^
	@echo "$(GREEN) Libfts archive has been created $(RESET)"

$(OBJS) : $(MANDATORY)
	@$(CC) $(CFLAGS) $^
	@echo "$(YELLOW) Libfts object files have been created $(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(RED) Libfts object files have been removed $(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED) Libfts archive has been removed $(RESET)"

re: fclean all
