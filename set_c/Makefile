RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RESET	= \033[0;37m
SKY		= \033[1;36m

GITHUB = git@github.com:TigranYavroyan/C_impl.git
GITHUB_FOLDER_NAME = chlp

SRCSPATH = ./srcs/
INCLPATH = ./includes/ ../libft/ ../list_c/includes/
SRCS = $(wildcard $(SRCSPATH)*.c)
OBJS = $(patsubst $(SRCSPATH)%.c, $(SRCSPATH)%.o, $(SRCS))
CFLAGS = -Wall -Wextra -Werror $(foreach H, $(INCLPATH), -I$(H))
NAME = libset.a

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rcs $@ $^
	@echo "$(GREEN) Sets archive has been created $(RESET)"

$(SRCSPATH)%.o : $(SRCSPATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW) Sets object files have been created $(RESET)"

clean :
	@rm -f $(OBJS)
	@echo "$(RED) Sets object files have been deleted $(RESET)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED) Sets executable file has been deleted $(RESET)"

re : fclean all

.PHONY : all clean fclean re
