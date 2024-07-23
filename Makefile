NAME=executable

FILES:=linked-lists/single-linked-list/IntSLLNode.cpp linked-lists/single-linked-list/IntSLList.cpp
FILES:=$(addprefix src/, $(FILES))
FILES_OBJS=$(FILES:.cpp=.o)
TEST_LINKED_LIST:=single-linked-list/IntSLLNode.cpp single-linked-list/IntSLList.cpp \
				  doubly-linked-list/DLLNode.cpp doubly-linked-list/DLList.cpp \
				  doubly-linked-list/CDLList.cpp
TEST_LINKED_LIST:=$(addprefix unit/linked-list/, $(TEST_LINKED_LIST))
TEST_STACK:= Stack.cpp
TEST_STACK:=$(addprefix unit/stack/, $(TEST_STACK))
TEST_QUEUE:= Queue.cpp
TEST_QUEUE:=$(addprefix unit/queue/, $(TEST_QUEUE))
TEST_DEQUE:= unit/deque/Deque.cpp
TEST_FILES:= asserts.cpp unit/recursion.cpp main.cpp $(TEST_LINKED_LIST) $(TEST_STACK) $(TEST_QUEUE) $(TEST_DEQUE)
TEST_FILES:=$(addprefix tests/, $(TEST_FILES))
TEST_FILES_OBJS=$(TEST_FILES:.cpp=.o)
INCLUDES=-I includes/ -I tests/
COMPILER=c++

all: $(NAME)

$(NAME): $(FILES_OBJS) src/main.cpp
	@$(COMPILER) --std=c++98 $(INCLUDES) $(FILES_OBJS) src/main.cpp -o $(NAME)

%.o: %.cpp
	$(COMPILER) $(INCLUDES) -c $< -o $@

unit: $(TEST_FILES_OBJS) $(FILES_OBJS)
	@$(COMPILER) $(INCLUDES) $(FILES_OBJS) $(TEST_FILES_OBJS) -o unit
	@valgrind --leak-check=full -q ./unit
	@rm -rf unit

e2e: $(NAME)
	@./tests/e2e/Program.sh $(realpath $(NAME))

clean:
	@rm -rf $(FILES_OBJS) $(TEST_FILES_OBJS)
