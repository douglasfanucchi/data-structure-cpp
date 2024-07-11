NAME=executable

FILES:=linked-lists/IntSLLNode.cpp linked-lists/IntSLList.cpp
FILES:=$(addprefix src/, $(FILES))
TEST_LINKED_LIST:=IntSLLNode.cpp IntSLList.cpp
TEST_LINKED_LIST:=$(addprefix unit/linked-list/, $(TEST_LINKED_LIST))
TEST_FILES:= asserts.cpp main.cpp $(TEST_LINKED_LIST)
TEST_FILES:=$(addprefix tests/, $(TEST_FILES))
INCLUDES=-I includes/
COMPILER=c++

all: $(NAME)

$(NAME): $(FILES) src/main.cpp
	@$(COMPILER) --std=c++98 $(INCLUDES) $(FILES) src/main.cpp -o $(NAME)

unit: $(TEST_FILES)
	@$(COMPILER) $(INCLUDES) -I tests/ $(FILES) $(TEST_FILES) -o unit
	@valgrind --leak-check=full -q ./unit
	@rm -rf unit

e2e: $(NAME)
	@./tests/e2e/Program.sh $(realpath $(NAME))
