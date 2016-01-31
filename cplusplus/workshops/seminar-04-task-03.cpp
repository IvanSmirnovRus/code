#include <iostream>
#include <map>
#include <stack>
#include <vector>

using std::cout;
using std::endl;
using std::string;

bool IsDigit(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

int GetDigit(char symbol) {
    return symbol - '0';
}

typedef int (*TOperation) (int, int);

int PostfixCalculate(const string& expression,
                     const std::map<char, TOperation>& operations) 
{
    std::stack<int, std::vector<int> > values;
    for (size_t i = 0; i < expression.size(); ++i) {
        char symbol = expression[i];

        if (IsDigit(symbol)) {
            values.push(GetDigit(symbol));
        } else {
            int rhsOperand = values.top();
            values.pop();
            int lhsOperand = values.top();
            values.pop();

            TOperation operation = operations.find(symbol)->second;
            values.push(operation(lhsOperand, rhsOperand));
        }
    }

    return values.top();
}

int OperationPlus(int x, int y) {
    return x + y;
}

int OperationMinus(int x, int y) {
    return x - y;
}

int OperationMultiply(int x, int y) {
    return x * y;
}

int OperationDivide(int x, int y) {
    return x / y;
}

std::map<char, TOperation> OperationsTable() {
    std::map<char, TOperation> operations;
    operations['+'] = OperationPlus;
    operations['-'] = OperationMinus;
    operations['*'] = OperationMultiply;
    operations['/'] = OperationDivide;

    return operations;
}

int main() {
    std::map<char, TOperation> operations = OperationsTable();

    cout << PostfixCalculate("723*-", operations) << endl;
    cout << PostfixCalculate("812+-", operations) << endl;
    cout << PostfixCalculate("911+11++-", operations) << endl;
    cout << PostfixCalculate("5172/-+10+-", operations) << endl;

    return 0;
}
