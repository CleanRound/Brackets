#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return true;
    else if (character1 == '{' && character2 == '}')
        return true;
    else if (character1 == '[' && character2 == ']')
        return true;
    else
        return false;
}

bool areParenthesesBalanced(const std::string& expression) {
    std::stack<char> stack;
    for (char bracket : expression) {
        if (bracket == '(' || bracket == '{' || bracket == '[') {
            stack.push(bracket);
        }
        else if (bracket == ')' || bracket == '}' || bracket == ']') {
            if (stack.empty() || !isMatchingPair(stack.top(), bracket)) {
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}

int main() {
    string input;
    cout << "Enter the expression: ";
    getline(cin, input);

    if (areParenthesesBalanced(input)) {
        cout << "The expression has balanced parentheses." << endl;
    }
    else {
        cout << "The expression has unbalanced parentheses." << endl;
    }

    return 0;
}
