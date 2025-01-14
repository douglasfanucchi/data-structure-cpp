NAME=executable

GRAPHS_FILES:=GraphMatrix.cpp DGraphMatrix.cpp PonderedGraphMatrix.cpp GraphLinkedList.cpp DGraphLinkedList.cpp \
				Maze.cpp
GRAPHS_FILES:=$(addprefix graphs/, $(GRAPHS_FILES))
FILES:=recursion.cpp linked-lists/single-linked-list/IntSLLNode.cpp linked-lists/single-linked-list/IntSLList.cpp\
		$(GRAPHS_FILES)
FILES:=$(addprefix src/, $(FILES))
FILES_OBJS=$(FILES:.cpp=.o)
TEST_LINKED_LIST:=single-linked-list/IntSLLNode.cpp single-linked-list/IntSLList.cpp \
				  doubly-linked-list/DLLNode.cpp doubly-linked-list/DLList.cpp \
				  doubly-linked-list/CDLList.cpp
TEST_LINKED_LIST:=$(addprefix unit/linked-list/, $(TEST_LINKED_LIST))
TEST_STACK:= Stack.cpp
TEST_STACK:=$(addprefix unit/stack/, $(TEST_STACK))
TEST_QUEUE:= Queue.cpp PriorityQueueMin.cpp
TEST_QUEUE:=$(addprefix unit/queue/, $(TEST_QUEUE))
TEST_DEQUE:= unit/deque/Deque.cpp
TEST_TREES:= binary-tree/BST.cpp binary-tree/BTNode.cpp binary-tree/TBST.cpp binary-tree/MinHeap.cpp
TEST_TREES:= $(addprefix unit/tree/, $(TEST_TREES))
TEST_GRAPHS:= $(addprefix unit/, $(GRAPHS_FILES))
TEST_FILES:= asserts.cpp unit/recursion.cpp main.cpp $(TEST_LINKED_LIST) $(TEST_STACK) $(TEST_QUEUE) $(TEST_DEQUE) \
			 $(TEST_TREES) \
			 $(TEST_GRAPHS)
TEST_FILES:=$(addprefix tests/, $(TEST_FILES))
TEST_FILES_OBJS=$(TEST_FILES:.cpp=.o)
INCLUDES=-I includes/ -I tests/
COMPILER=c++

all: $(NAME)

$(NAME): $(FILES_OBJS) src/main.cpp
	@$(COMPILER) --std=c++98 $(INCLUDES) $(FILES_OBJS) src/main.cpp -o $(NAME)

%.o: %.cpp
	$(COMPILER) $(INCLUDES) -g -c $< -o $@

unit: $(TEST_FILES_OBJS) $(FILES_OBJS)
	@$(COMPILER) $(INCLUDES) $(FILES_OBJS) $(TEST_FILES_OBJS) -g -o unit
	@valgrind --leak-check=full -q ./unit
	@rm -rf unit

build: unit.dockerfile clean
	docker build . -t dsa-cpp -f unit.dockerfile

run: build
	docker run --rm dsa-cpp

e2e: $(NAME)
	@./tests/e2e/Program.sh $(realpath $(NAME))

clean:
	@rm -rf $(FILES_OBJS) $(TEST_FILES_OBJS)
