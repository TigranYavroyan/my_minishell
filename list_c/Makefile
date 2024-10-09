RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RESET	= \033[0;37m
SKY		= \033[1;36m

GITHUB = git@github.com:TigranYavroyan/C_impl.git
GITHUB_FOLDER_NAME = chlp

SRCSPATH = ./srcs/
INCLPATH = ./includes/ ../libft/
SRCS = $(wildcard $(SRCSPATH)*.c)
OBJS = $(patsubst $(SRCSPATH)%.c, $(SRCSPATH)%.o, $(SRCS))
CFLAGS = -g $(foreach H, $(INCLPATH), -I$(H))
NAME = liblist.a

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rcs $@ $^
	@echo "$(GREEN) Lists archive has been created $(RESET)"

$(SRCSPATH)%.o : $(SRCSPATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW) Lists object files have been created $(RESET)"

clean :
	@rm -f $(OBJS)
	@echo "$(RED) Lists object files have been deleted $(RESET)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED) Lists executable file has been deleted $(RESET)"

re : fclean all

grm :
	@rm -rf $(GITHUB_FOLDER_NAME)
	@echo "$(RED) The git repo has been removed $(RESET)"

copy :
	@cp -r Makefile includes srcs $(GITHUB_FOLDER_NAME)/list_c
	@echo "$(SKY) The content copied in git repo $(RESET)"

clone :
	@git clone $(GITHUB) $(GITHUB_FOLDER_NAME)
	@echo "$(SKY) Git repo has been cloned $(RESET)"

push :
	@git add .
	@git commit -m "something done"
	@git push
	@echo "$(SKY) Pushed $(RESET)"

leaks :
	valgrind ./$(NAME)

.PHONY : all clean fclean re push copy clone grm leaks
