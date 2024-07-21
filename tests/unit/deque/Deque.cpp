#include <asserts.hpp>
#include <Deque.hpp>

void test_should_create_a_deque()
{
    Deque<int> deque;

    ASSERT_TRUE(deque.isEmpty());
}

void test_should_insert_element_into_deque()
{
    Deque<int> deque;

    deque.pushFront(1);

    ASSERT_FALSE(deque.isEmpty());
}

void test_should_insert_two_elements_into_deque_front()
{
    Deque<int> deque;

    deque.pushFront(1);
    deque.pushFront(2);

    ASSERT_FALSE(deque.isEmpty());
}

void test_should_insert_eight_elements_into_deque()
{
    Deque<int> deque;

    deque.pushFront(1);
    deque.pushFront(2);
    deque.pushFront(3);
    deque.pushFront(4);
    deque.pushFront(5);
    deque.pushFront(6);
    deque.pushFront(7);
    deque.pushFront(8);

    ASSERT_FALSE(deque.isEmpty());
}

void test_should_insert_multiple_elements_into_deque()
{    
    Deque<int> deque;

    deque.pushFront(1);
    deque.pushFront(2);
    deque.pushFront(3);
    deque.pushFront(4);
    deque.pushFront(5);
    deque.pushFront(6);
    deque.pushFront(7);
    deque.pushFront(8);
    deque.pushFront(9);
    deque.pushFront(10);

    ASSERT_FALSE(deque.isEmpty());
}

void test_should_pop_a_element_from_deque_front()
{
    Deque<int> deque;
    deque.pushFront(1);

    int result = deque.popFront();

    ASSERT_EQ(1, result);
    ASSERT_TRUE(deque.isEmpty());
}

void test_should_pop_three_elements_from_deque_front()
{
    Deque<int> deque;
    deque.pushFront(1);
    deque.pushFront(2);
    deque.pushFront(3);

    int result = deque.popFront();
    deque.popFront();
    deque.popFront();

    ASSERT_EQ(3, result);
    ASSERT_TRUE(deque.isEmpty());
}

void test_should_pop_front_an_element_from_empty_deque()
{
    Deque<int> deque;
    const char *expected = "empty deque";

    try {
        deque.popFront();
    } catch(const char *result) {
        ASSERT_STREQ(expected, result);
    }
}

void test_should_access_deque_element_in_a_big_O_of_one()
{
    Deque<std::string> deque;
    std::string expected("lima");
    deque.pushFront("douglas");
    deque.pushFront("de");
    deque.pushFront("lima");
    deque.pushFront("fanucchi");

    std::string result = deque[2];
    ASSERT_STREQ(expected, result);
}

void RUN_DEQUE_TEST_SUITE()
{
    test_should_create_a_deque();
    test_should_insert_element_into_deque();
    test_should_insert_two_elements_into_deque_front();
    test_should_insert_eight_elements_into_deque();
    test_should_insert_multiple_elements_into_deque();
    test_should_pop_a_element_from_deque_front();
    test_should_pop_three_elements_from_deque_front();
    test_should_pop_front_an_element_from_empty_deque();
    test_should_access_deque_element_in_a_big_O_of_one();
}
