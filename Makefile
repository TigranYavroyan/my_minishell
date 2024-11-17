RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RESET	= \033[0;37m
SKY		= \033[1;36m

NAME = minishell

SRC_DIR = srcs/
OBJ_DIR = build/
SUBDIRS = builtin/ others/ signal/

LIBFTPATH = libft/
LISTPATH = list_c/
BSTPATH = bst_c/
SETPATH = set_c/

INCLPATH = includes/ $(LIBFTPATH) $(LISTPATH)includes/ $(BSTPATH)includes/ $(SETPATH)includes/

SRCDIRS = $(addprefix $(SRC_DIR)/, $(SUBDIRS))
SRCS = $(notdir $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))) $(notdir $(SRC_DIR)/main.c)
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

UNAME = $(shell uname -s)
ARCH = $(shell uname -m)
ifeq ($(UNAME), Darwin)
	ifeq ($(ARCH), arm64)
		LREADLINE = -L/opt/homebrew/Cellar/readline/8.2.13/lib -l readline
		INCLPATH += /opt/homebrew/Cellar/readline/8.2.13/include
	else
		LREADLINE = -Lreadline_local/lib -lreadline
		INCLPATH += ./readline_local/include/
	endif
else
	LREADLINE = -Lreadline_local -lreadline
endif

CFLAGS = -Wall -Wextra -Werror
INCLUDES = $(foreach H, $(INCLPATH), -I $(H))

LIBFT = $(LIBFTPATH)libft.a
LIST = $(LISTPATH)liblist.a
BST = $(BSTPATH)libbst.a
SET = $(SETPATH)libset.a

LIBFLAGS = -L$(BSTPATH) -lbst -L$(LISTPATH) -llist -L$(LIBFTPATH) -lft -L$(SETPATH) -lset $(LREADLINE)

all : $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ) $(BST) $(LIST) $(LIBFT) $(SET) Makefile
	@$(CC) $(OBJ) $(LIBFLAGS) -o $(NAME)
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

$(SET) :
	@make -C $(SETPATH) all
	@echo "$(YELLOW) Sets object files have been created $(RESET)"

clean :
	@make -C $(LIBFTPATH) clean
	@make -C $(LISTPATH) clean
	@make -C $(BSTPATH) clean
	@make -C $(SETPATH) clean
	@rm -f $(OBJ_DIR)/*.o
	@rm -rf $(OBJ_DIR)
	@echo "$(RED) Object files have been deleted $(RESET)"

fclean : clean
	@make -C $(LIBFTPATH) fclean
	@make -C $(LISTPATH) fclean
	@make -C $(BSTPATH) fclean
	@make -C $(SETPATH) fclean
	@rm -f $(NAME)
	@echo "$(RED) Executable file has been deleted $(RESET)"

re : fclean all

config:
	mkdir -p readline_local
	./readline_config.sh readline_local

.PHONY : all clean fclean re config
