#include <asserts.hpp>
#include <DLLNode.hpp>

void test_should_create_dll_node()
{
    DLLNode<int> intNode(1);
    ASSERT_TRUE(intNode.next == NULL);
    ASSERT_TRUE(intNode.prev == NULL);

    DLLNode<char> charNode('1');
    ASSERT_TRUE(charNode.next == NULL);
    ASSERT_TRUE(charNode.prev == NULL);

    DLLNode<std::string> stringNode("ola mundo");
    ASSERT_TRUE(stringNode.next == NULL);
    ASSERT_TRUE(stringNode.prev == NULL);

    DLLNode<float> floatNode(1.0);
    ASSERT_TRUE(floatNode.next == NULL);
    ASSERT_TRUE(floatNode.prev == NULL);
}

void RUN_DLL_NODE_SUITE()
{
    test_should_create_dll_node();
}
