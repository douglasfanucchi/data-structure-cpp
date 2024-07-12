#include <IntSLLNode.hpp>

IntSLLNode::IntSLLNode(int value, IntSLLNode *next)
{
    this->next = next;
    this->value = value;
}
