RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RESET	= \033[0;37m
SKY		= \033[1;36m

CC = gcc
SRCSPATH = ./srcs/
LIBFTPATH = ../libft/

INCLPATH = ./includes/ $(LIBFTPATH)
SRCS = $(wildcard $(SRCSPATH)*.c)
OBJS = $(patsubst $(SRCSPATH)%.c, $(SRCSPATH)%.o, $(SRCS))
#-Wall -Wextra -Werror
CFLAGS = -g -Wall -Wextra -Werror $(foreach H, $(INCLPATH), -I$(H))

NAME = bst.a
LIBFT = $(LIBFTPATH)libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rcs $@ $^
	@echo "$(GREEN) BST archive has been created $(RESET)"

$(LIBFT) :
	@make -C $(LIBFTPATH) all
	@echo "$(YELLOW) Lists object files have been created $(RESET)"

$(SRCSPATH)%.o : $(SRCSPATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW) BST object files have been created $(RESET)"

clean :
	@make -C $(LIBFTPATH) clean
	@rm -f $(OBJS)
	@echo "$(RED) BST object files have been deleted $(RESET)"

fclean : clean
	@make -C $(LIBFTPATH) fclean
	@rm -f $(NAME)
	@echo "$(RED) BST archive has been deleted $(RESET)"

re : fclean all

leaks :
	valgrind --leak-check=full ./$(NAME)

.PHONY : all clean fclean re leaks
