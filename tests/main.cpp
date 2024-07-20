#include <iostream>
#include <tests.hpp>

int main()
{
    RUN_INT_SLL_NODE_SUITE();
    RUN_INT_SLLIST_SUITE();
    RUN_DLL_NODE_SUITE();
    RUN_DOUBLY_LINKED_LIST_SUITE();
    RUN_CIRCULAR_DOUBLY_LINKED_LIST_SUITE();
    RUN_STACK_TEST_SUITE();
    RUN_QUEUE_TEST_SUITE();
    RUN_DEQUE_TEST_SUITE();
    std::cout << std::endl;
}
