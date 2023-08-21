NAME 		= number_sort

CC 		= cc
CFLAGS		= -Wall -Werror -Wextra
DFLAGS		= $(CFLAGS) -g -fsanitize=address

OBJDIR		= build/
SRC		= src/
UTILS		= $(SRC)utils/
ARRAYS		= $(SRC)arrays/
LISTS		= $(SRC)lists/
SRC_LISTS	= $(LISTS)lst_bogo.c $(LISTS)lst_bubble.c $(LISTS)lst_insertion.c  \
		  $(LISTS)lst_quick.c $(LISTS)lst_selection.c $(LISTS)lst_tree.c  \
		  $(LISTS)lst_radix.c
SRC_ARRAYS	= $(ARRAYS)arr_bogo.c $(ARRAYS)arr_bubble.c $(ARRAYS)arr_insertion.c  \
		  $(ARRAYS)arr_quick.c $(ARRAYS)arr_radix.c $(ARRAYS)arr_selection.c \
		   $(ARRAYS)arr_tree.c 
SRC_UTILS	= $(UTILS)lists.c $(UTILS)split.c $(UTILS)utils.c $(UTILS)tree_utils.c \
		  $(UTILS)arrays.c $(UTILS)spam.c 	
SRC_MAIN 	= $(SRC)main.c $(SRC)algo_tester.c $(SRC)list_sorter.c $(SRC)array_sorter.c
SOURCES 	= $(SRC_MAIN) $(SRC_UTILS) $(SRC_LISTS) $(SRC_ARRAYS)
OBJ 		= $(subst $(UTILS),$(OBJDIR),$(SRC_UTILS:.c=.o)) \
			$(subst $(SRC),$(OBJDIR),$(SRC_MAIN:.c=.o)) \
			$(subst $(LISTS),$(OBJDIR),$(SRC_LISTS:.c=.o)) \
			$(subst $(ARRAYS),$(OBJDIR),$(SRC_ARRAYS:.c=.o)) \

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@echo "Compiling program"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJDIR):
	@mkdir $(OBJDIR)

$(OBJ):
	@echo "Compiling object files"
	@$(CC) -c $(SOURCES) $(CFLAGS)
	@mv *.o $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: re
	./$(NAME) "10 2 4 5 6 100 69 30"

debug: $(OBJDIR)
	@echo "[DEBUG] Compiling object files"
	@$(CC) -c $(SOURCES) $(DFLAGS)
	@mv *.o $(OBJDIR)
	@echo "[DEBUG] Compiling program"
	@$(CC) $(DFLAGS) -o $(NAME) $(OBJ)

leaks:
	@valgrind ./$(NAME) "10 2 4 5 6 100 69 30"


.PHONY: all clean fclean re debug leaks run
