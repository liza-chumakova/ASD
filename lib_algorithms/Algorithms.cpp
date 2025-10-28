#include "Algorithms.h"
#include "../lib_stack/stack.h"

#include <string>

int main()
{
    return 0;
}

bool check_same(std::string left, std::string right) {
    if (((left == '(') && (right == ')')) || ((left == '{') && (right == '}')) || ((left == '[') && (right == ']'))) {
        return true;
    }
    return false;
}

bool check_breckets(std::string toCheck) {
    Stack<std::string> checking(toCheck.size());
    if (toCheck.size() == 0) {return true;}
    //Проверка если закрывающие в начале или открывающие в конце
    if (check_same(toCheck[0], ')') || check_same(toCheck[0], '}') || check_same(toCheck[0], ']')) {return false}
    if (check_same(toCheck[toCheck.size() - 1], '(') || check_same(toCheck[toCheck.size() - 1], '{') || check_same(toCheck[toCheck.size() - 1], '[')) {return false}
    //В ином случае
    if (toCheck.size()%2 == 1) {return false};
    else{
        for (int i = 0; i < toCheck.size(); ++i) {
            if ((toCheck[i]== '(') || (toCheck[i]== '{') || (toCheck[i]== '[')) {
                checking.push(toCheck[i]);
            }
            //     for (int j = i; j < toCheck.size(); ++j) {
            //         if (check_same(checking.top(), toCheck[j])) {
            //             checking.pop();
            //             toCheck.erase(j,1);
            //             break;
            //         }
            //     }
            // }
            //else if ((toCheck[i] == '(') || (toCheck[i] == '{') || (toCheck[i] == '[')) {
            else {
                if (checking.is_empty()) {return false}

                char ch = checking.top();
                checking.pop();

                if ((toCheck[i] == ')' && ch != '(') || (toCheck[i] == '}' && ch != '{') || (toCheck[i] == ']' && ch != '[')) {
                    return false;
                }

            }
        }
        // if (checking.is_empty() && (toCheck.find(')') == 0) && (toCheck.find('}') == 0) && (toCheck.find('}') == 0)) {
        //     return true;
        // }
        // else {
        //     return false;
        return checking.is_empty();
        }
    
}