##
## EPITECH PROJECT, 2022
## B-MUL-100-REN-1-1-myradar-jean-yanis.jeffroy
## File description:
## Makefile
##

PROJECT_NAME			=	my_paint
NAME					=	my_paint

SRC 					= 	$(shell find src/ -name '*.c')

BUILD_DIR				=	build
OBJ						=	$(SRC:%.c=$(BUILD_DIR)/%.o)

LIB_FOLDER				=	mars_lib

CFLAGS					:=	-I include/ 							\
							-I $(LIB_FOLDER)/include/				\
							-I $(LIB_FOLDER)/my_printf/include/		\
							-I $(LIB_FOLDER)/my_stdlib/include/		\
							-I $(LIB_FOLDER)/my_arraylib/include/

WFLAGS					:=	-Wall -Wextra

LDLIBS 	:=	-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm
LDLIBS	+=	-L $(LIB_FOLDER) -lmars

all:	$(NAME)

$(NAME):	$(OBJ)
	@mkdir -p $(BUILD_DIR)
	@make -s -C $(LIB_FOLDER)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(WFLAGS) $(LDLIBS)\
	&& echo "\033[1;32m[OK]\033[0m" $(NAME)\
	|| echo "\033[1;31m[KO]\033[0m" $(NAME)

$(BUILD_DIR)/%.o:	%.c
	@mkdir -p $(dir $@)
	@gcc -c -o $@ $< $(CFLAGS) $(WFLAGS)\
	&& echo "\033[1;32m[OK]\033[0m" $<\
	|| echo "\033[1;31m[KO]\033[0m" $<

debug:	CFLAGS += -g3
debug:	re

clean:
	@make -s -C $(LIB_FOLDER) clean
	@echo "\033[1;31m[LIB CLEAN]\033[0m" $(LIB_FOLDER)
	@for file in $(BUILD_DIR)/*; do\
		if [ -d $$file ]; then\
			rm -rf $$file;\
			echo "\033[1;31m[DELETED]\033[0m" $$file;\
		fi;\
	done
	@echo "\033[1;31m[CLEAN]\033[0m" $(PROJECT_NAME)
	@rm -f $(shell find -name '*.gc*' -type f)

fclean: clean
	@make -s -C $(LIB_FOLDER) fclean
	@echo "\033[1;31m[LIB FCLEAN]\033[0m" $(LIB_FOLDER)
	@rm -f $(TEST_NAME)
	@echo "\033[1;31m[DELETED]\033[0m" $(TEST_NAME)
	@rm -rf $(BUILD_DIR)
	@echo "\033[1;31m[DELETED]\033[0m" $(BUILD_DIR)
	@rm -f $(NAME)
	@echo "\033[1;31m[DELETED]\033[0m" $(NAME)

re:	fclean all

tests_run:	CFLAGS += -lcriterion --coverage
tests_run:	fclean
	@if [ ! -d "tests" ]; then\
		echo "\033[1;31m[ERROR]\033[0m" "No tests directory";\
		exit 1;\
	fi
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_TESTS_DIR)
	@gcc -o $(TEST_NAME) $(TEST_SRC) $(SRC) $(CFLAGS) $(WFLAGS) $(CRITERION)\
	&& echo "\033[1;32m[OK]\033[0m" $(TEST_NAME)\
	|| echo "\033[1;31m[KO]\033[0m" $(TEST_NAME)
	@./$(TEST_NAME)
	mv *.gc* $(BUILD_TESTS_DIR)
	gcovr --exclude tests/

.PHONY: all clean fclean re debug tests_run

.SILENT: all clean fclean re debug tests_run

%:
	@echo "\033[1;31m[ERROR]\033[0m" "No rule to make target '$@'"
