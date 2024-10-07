RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RESET	= \033[0;37m
SKY		= \033[1;36m

CC = gcc
SRCSPATH = ./srcs/
LIBFTPATH = ./libft/
LISTPATH = ./list_c/
BSTPATH = ./bst_c/
SETPATH = ./set_c/
INCLPATH = ./includes/ $(SETPATH)includes/ $(LIBFTPATH) $(LISTPATH)includes/ $(BSTPATH)includes/ ./readline_local/include/

SRCS = $(wildcard $(SRCSPATH)*.c)
OBJS = $(patsubst $(SRCSPATH)%.c, $(SRCSPATH)%.o, $(SRCS))
#
CFLAGS = -g -Wall -Wextra -Werror $(foreach H, $(INCLPATH), -I$(H))
EXECFLAGS = -lreadline -lncurses #-fsanitize=address

UNAME = $(shell uname -s)
ifeq ($(UNAME), Darwin)
	LREADLINE =  -Lreadline_local/lib -lreadline
else
	LREADLINE = -lreadline
endif

# -g
LIBFT = $(LIBFTPATH)libft.a
LIST = $(LISTPATH)list.a
BST = $(BSTPATH)bst.a
SET = $(SETPATH)set.a
NAME = minishell

all : $(NAME)

#
$(NAME) : $(OBJS) $(BST) $(LIST) $(LIBFT) $(SET)
	@$(CC) $^ $(EXECFLAGS) $(LREADLINE) -o $@
	@echo "$(GREEN) Executable file has been created $(RESET)"

$(BST) :
	@make -C $(BSTPATH) all
	@echo "$(YELLOW) BSTs object files have been created $(RESET)"

$(LIBFT) :
	@make -C $(LIBFTPATH) all
	@echo "$(YELLOW) Libfts object files have been created $(RESET)"

$(LIST) :
	@make -C $(LISTPATH) all
	@echo "$(YELLOW) Lists object files have been created $(RESET)"

$(SET) :
	@make -C $(SETPATH) all
	@echo "$(YELLOW) Sets object files have been created $(RESET)"

$(SRCSPATH)%.o : $(SRCSPATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW) Object files have been created $(RESET)"

clean :
	@make -C $(LIBFTPATH) clean
	@make -C $(LISTPATH) clean
	@make -C $(BSTPATH) clean
	@make -C $(SETPATH) clean
	@rm -f $(OBJS)
	@echo "$(RED) Object files have been deleted $(RESET)"

fclean : clean
	@make -C $(LIBFTPATH) fclean
	@make -C $(LISTPATH) fclean
	@make -C $(BSTPATH) fclean
	@make -C $(SETPATH) fclean
	@rm -f $(NAME)
	@echo "$(RED) Executable file has been deleted $(RESET)"

re : fclean all

push :
	@git add .
	@git commit -m "added something"
	@git push
	@echo "$(SKY) Pushed! $(RESET)"

config:
	mkdir -p readline_local
	./readline_config.sh readline_local

leaks:
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=.vgignore ./$(NAME)

.PHONY : all clean fclean re config push
