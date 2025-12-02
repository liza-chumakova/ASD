#include "../lib_list/list.h"

template <typename T>
bool checkListCycleTurtleAndRabbit(const Node<T>* head) {
    if(head == nullptr || head->_next == nullptr) {
        return false;
    }

    const Node<T>* rabbit = head;//установка обоих на голову
    const Node<T>* turtle = head;

    while (rabbit != nullptr && rabbit->_next != nullptr) { //скачем пока животные не дойдут до конца списка - если дойдут, то цикла автоматически нет
        turtle = turtle->_next;
        rabbit = rabbit->_next->_next;

        if (rabbit == turtle) { //если они встретились, то цикл есть

            return true;
        }
    }

    return false;
}

template <typename T>
bool checkListCyclePointer(Node<T>* head) {
    if (head == nullptr || head->_next == nullptr) {
        return false;
    }
    
    Node<T>* current = head;
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;
    Node<T>* first = head;
    bool has_cycle = false;
    
    // Разворачиваем указатели
    while (current != nullptr) {
        next = current->_next;
        current->_next = prev;
        
        // Проверяем, не вернулись ли мы к началу
        if (next == first) {
            has_cycle = true;
            break;
        }
        
        prev = current;
        current = next;
    }
    
    // Восстанавливаем список
    //  prev указывает на последний обработанный элемент
    // current = nullptr если нет цикла или current указывает на узел перед циклом
    
    if (has_cycle) {
        // В случае цикла: current указывает на узел, который ссылается на first
        // prev - последний элемент в обратном порядке
        Node<T>* restore_current = prev;
        Node<T>* restore_prev = nullptr;
        
        // Восстанавливаем до узла current
        while (restore_current != nullptr && restore_current != current) {
            next = restore_current->_next;
            restore_current->_next = restore_prev;
            restore_prev = restore_current;
            restore_current = next;
        }
        
        // Восстанавливаем связь с первым элементом
        if (current != nullptr) {
            current->_next = restore_prev;
        }
        
    }
    else {
        // Без цикла- полностью восстанавливаем список
        current = prev;
        prev = nullptr;
        
        while (current != nullptr) {
            next = current->_next;
            current->_next = prev;
            prev = current;
            current = next;
        }
    }
    
    return has_cycle;
}

//возврат указателя на место поломки (Node* где список зациклился)
template <typename T>
Node<T>* FindProblemNode(Node<T>* head) {
    if (!checkListCycleTurtleAndRabbit(head)) {
        return nullptr;
    }

    Node<T>* turtle = const_cast<Node<T>*>(head);
    Node<T>* rabbit = const_cast<Node<T>*>(head);

    do {
        turtle = turtle->_next;
        rabbit = rabbit->_next->_next;
    } while (turtle != rabbit);
    
    //Находим начало цикла
    turtle = const_cast<Node<T>*>(head);
    
    //цикл начинается с головы
    if (turtle == rabbit) {
        Node<T>* current = head;
        while (current->_next != head) {
            current = current->_next;
        }
        return current;
    }

    Node<T>* prev = rabbit;
    while (turtle != rabbit) {
        prev = rabbit;
        turtle = turtle->_next;
        rabbit = rabbit->_next;
    }
    
    //узел который ссылается на начало цикла
    return prev;
}