#include "../lib_list/list.h"

template <typename T>
bool checkListCycle(const Node<T>* head) {
    if(head == nullptr || head->_next == nullptr) {
        return false;
    }

    const Node<T>* rabbit = head;
    const Node<T>* turtle = head;

    while (rabbit != nullptr && rabbit->_next != nullptr) {
        turtle = turtle->_next;
        rabbit = rabbit->_next->_next;

        if (rabbit == turtle) {
            return true;
        }
    }

    return false;
}