#include <asserts.hpp>
#include <MinHeap.hpp>

static void test_should_create_an_empty_heap()
{
    MinHeap<int> heap(0);

    ASSERT_TRUE(heap.isEmpty());
}

static void test_should_create_and_insert_elements_into_heap()
{
    MinHeap<int> heap(4);
    heap.insert(2);
    heap.insert(5);
    heap.insert(9);
    heap.insert(1);

    heap.build();

    ASSERT_FALSE(heap.isEmpty());
    ASSERT_EQ(1, heap[0]);
    ASSERT_EQ(2, heap[1]);
    ASSERT_EQ(9, heap[2]);
    ASSERT_EQ(5, heap[3]);
}

void RUN_MIN_HEAP_TEST_SUITE()
{
    test_should_create_an_empty_heap();
    test_should_create_and_insert_elements_into_heap();
}
