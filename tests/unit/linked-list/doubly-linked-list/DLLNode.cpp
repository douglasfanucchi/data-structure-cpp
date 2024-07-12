#include <asserts.hpp>
#include <DLLNode.hpp>
#include <math.h>

void test_should_create_dll_node()
{
    DLLNode<int> intNode(1);
    ASSERT_TRUE(intNode.next == NULL);
    ASSERT_TRUE(intNode.prev == NULL);
    ASSERT_EQ(1, intNode.value);

    DLLNode<char> charNode('1');
    ASSERT_TRUE(charNode.next == NULL);
    ASSERT_TRUE(charNode.prev == NULL);
    ASSERT_EQ('1', charNode.value);

    DLLNode<std::string> stringNode("ola mundo");
    ASSERT_TRUE(stringNode.next == NULL);
    ASSERT_TRUE(stringNode.prev == NULL);
    ASSERT_STREQ("ola mundo", stringNode.value);

    DLLNode<float> floatNode(1.0);
    ASSERT_TRUE(floatNode.next == NULL);
    ASSERT_TRUE(floatNode.prev == NULL);
    ASSERT_TRUE(fabs(1.0 - floatNode.value) < 0.001);
}

void RUN_DLL_NODE_SUITE()
{
    test_should_create_dll_node();
}
