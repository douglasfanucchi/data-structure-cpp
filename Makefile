NAME=executable

FILES:=linked-lists/single-linked-list/IntSLLNode.cpp linked-lists/single-linked-list/IntSLList.cpp
FILES:=$(addprefix src/, $(FILES))
TEST_LINKED_LIST:=single-linked-list/IntSLLNode.cpp single-linked-list/IntSLList.cpp \
				  doubly-linked-list/DLLNode.cpp doubly-linked-list/DLList.cpp \
				  doubly-linked-list/CDLList.cpp
TEST_LINKED_LIST:=$(addprefix unit/linked-list/, $(TEST_LINKED_LIST))
TEST_STACK:= Stack.cpp
TEST_STACK:=$(addprefix unit/stack/, $(TEST_STACK))
TEST_QUEUE:= Queue.cpp
TEST_QUEUE:=$(addprefix unit/queue/, $(TEST_QUEUE))
TEST_FILES:= asserts.cpp main.cpp $(TEST_LINKED_LIST) $(TEST_STACK) $(TEST_QUEUE)
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
