RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RESET	= \033[0;37m
SKY		= \033[1;36m

NAME = minishell
BRANCH = las

SRC_DIR = srcs/
OBJ_DIR = build/
SUBDIRS = builtin/ others/ signal/

LIBFTPATH = libft/
LISTPATH = list_c/
BSTPATH = bst_c/

INCLPATH = includes/ $(LIBFTPATH) $(LISTPATH)includes/ $(BSTPATH)includes/

SRCDIRS = $(addprefix $(SRC_DIR)/, $(SUBDIRS))
SRCS = $(notdir $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))) $(notdir $(SRC_DIR)/main.c)
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

CFLAGS = -Wall -Wextra -Werror
DEBUG = -g -lncurses -fsanitize=address
INCLUDES = $(foreach H, $(INCLPATH), -I $(H))

UNAME = $(shell uname -s)
ARCH = $(shell uname -m)
ifeq ($(UNAME), Darwin)
	ifeq ($(ARCH), arm64)
		LREADLINE = -L/opt/homebrew/Cellar/readline/8.2.13/lib -l readline
		INCLPATH += /opt/homebrew/Cellar/readline/8.2.13/include/readline
	else
		LREADLINE = -L/usr/lib -lreadline
	endif
else
	LREADLINE = -Lreadline_local -lreadline
endif

LIBFT = $(LIBFTPATH)libft.a
LIST = $(LISTPATH)liblist.a
BST = $(BSTPATH)libbst.a

LIBFLAGS = -L$(BSTPATH) -lbst -L$(LISTPATH) -llist -L$(LIBFTPATH) -lft $(LREADLINE)

all : $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ) $(BST) $(LIST) $(LIBFT) Makefile
	@$(CC) $(OBJ) $(DEBUG) $(LIBFLAGS)  -o $(NAME)
	@echo "$(GREEN) Executable file has been created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c Makefile
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BST) :
	@make -C $(BSTPATH) all
	@echo "$(YELLOW) BSTs object files have been created $(RESET)"

$(LIBFT) :
	@make -C $(LIBFTPATH) all
	@echo "$(YELLOW) Libfts object files have been created $(RESET)"

$(LIST) :
	@make -C $(LISTPATH) all
	@echo "$(YELLOW) Lists object files have been created $(RESET)"

clean :
	@make -C $(LIBFTPATH) clean
	@make -C $(LISTPATH) clean
	@make -C $(BSTPATH) clean
	@rm -f $(OBJ_DIR)/*.o
	@rm -rf $(OBJ_DIR)
	@echo "$(RED) Object files have been deleted $(RESET)"

fclean : clean
	@make -C $(LIBFTPATH) fclean
	@make -C $(LISTPATH) fclean
	@make -C $(BSTPATH) fclean
	@rm -f $(NAME)
	@echo "$(RED) Executable file has been deleted $(RESET)"

re : fclean all

push :
	@git add .
	@git commit -m "added something"
	@git push
	@echo "$(SKY) Pushed! $(RESET)"

git:
	@read -p "Enter commit message: " msg; \
	git add .; \
	git commit -m "$$msg"; \
	git push -u origin $(BRANCH)

config:
	mkdir -p readline_local
	./readline_config.sh readline_local

leaks:
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=.vgignore ./$(NAME)

.PHONY : all clean fclean re config push git
