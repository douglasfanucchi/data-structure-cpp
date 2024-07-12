#include <asserts.hpp>
#include <DLList.hpp>

void test_should_create_double_linked_list()
{
    DLList<std::string> list;

    ASSERT_TRUE(list.isEmpty());
}

void RUN_DOUBLE_LINKED_LIST_SUITE()
{
    test_should_create_double_linked_list();
}
