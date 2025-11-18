#include "Algorithms.h"
#include "../lib_stack/stack.h"

#include <string>

int main()
{
    return 0;
}

bool check_same(char left, char right) {
    if (((left == '(') && (right == ')')) || ((left == '{') && (right == '}')) || ((left == '[') && (right == ']'))) {
        return true;
    }
    return false;
}

bool check_brackets(const std::string& toCheck) {
    Stack<char> stack(toCheck.length());

    for (int i = 0; i < toCheck.length(); ++i) {
        char c = toCheck[i];
        
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (stack.is_empty()) {
                return false;
            }
            
            char top = stack.top();
            stack.pop();
            
            if (!check_same(top, c)) {
                return false;
            }
        }
    }

    return stack.is_empty();
}
