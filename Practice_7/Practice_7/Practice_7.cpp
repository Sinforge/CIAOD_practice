// Practice 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Stack {
private:
    int* elements;
    char* operations;

    int size_elements = 0;
    int size_operations = 0;
public:
 
    int GetElementsSize() {
        return size_elements;
    }
    int GetOperationsSize() {
        return size_operations;
    }
    int GetLastElement() {
        return elements[size_elements - 1];
    }
    char GetLastOperation() {
        return operations[size_operations - 1];

    }

        
        void element_push_back(int element) {
            int* new_elems = new int[size_elements + 1];
            for (int i = 0; i < size_elements; i++) {
                new_elems[i] = elements[i];
            }
            new_elems[size_elements] = element;
            delete[] elements;
            elements = new_elems;
            size_elements++;

       
    }
    int element_pop_back() {
        int last_elem = elements[size_elements - 1];
        int* new_mas2 = new int[size_elements - 1];
        for (int i = 0; i < size_elements - 1; i++) {
            new_mas2[i] = elements[i];
        }
        size_elements--;
        delete[] elements;
        elements = new_mas2;
        return last_elem;

       
    }
    void operation_push_back(char oper) {
       
        char* new_elems = new char[size_operations + 1];
        for (int i = 0; i < size_operations; i++) {
            new_elems[i] = operations[i];
        }
        new_elems[size_operations] = oper;
        delete[] operations;
        operations = new_elems;
        size_operations++;
        
    }
    char operation_pop_back() {
        
        char last_elem = operations[size_operations - 1];
        char* new_mas2 = new char[size_operations - 1];
        for (int i = 0; i < size_operations - 1; i++) {
            new_mas2[i] = operations[i];
        }
        size_operations--;
        delete[] operations;
        operations = new_mas2;
        return last_elem;
      
    }
};


vector<string> getwords(char str[]);
int calc(char str[]);
int doOperation(int num1, int num2, char operation);
void calcBrack(Stack& stack);
bool IsOper(char op);
int getRang(char oper);




int main()
{
    setlocale(LC_ALL, "");
    char s[255];
    cout << "Введите выражение в инфиксной форме: ";
    gets_s(s);
    int res = calc(s);
    cout << "Результат: " <<res;

}

int calc(char str[]) {
    Stack stack;
    vector<string> symbols = getwords(str);
    for (int i = 0; i < symbols.size(); i++) {
        if (isdigit(symbols[i][0])) {
            if (stack.GetElementsSize() == 0) {
                stack.element_push_back(stoi(symbols[i]));
            }
            else if (stack.GetLastOperation() == '(') {
                stack.element_push_back(stoi(symbols[i]));
            }
            else if (stack.GetLastOperation() == '/' || stack.GetLastOperation() == '*') {
                int res1 = stack.element_pop_back();
                int res2 = stoi(symbols[i]);
                stack.element_push_back(doOperation(res1, res2, stack.operation_pop_back()));

            }
            else {
                stack.element_push_back(stoi(symbols[i]));
            }
        }
        else if (symbols[i] == "(" || symbols[i] == ")") {
            if (symbols[i] == "(") {
                stack.operation_push_back(symbols[i][0]);
            }
            else {
                calcBrack(stack);
            }
        }
        else {
            if (stack.GetOperationsSize() >= 1) {
                if (getRang(symbols[i][0]) == getRang(stack.GetLastOperation())) {
                    int num2 = stack.element_pop_back();
                        int num1 = stack.element_pop_back();
                        int result = doOperation(num1, num2, stack.operation_pop_back());
                        stack.element_push_back(result);
                }
            }
            stack.operation_push_back(symbols[i][0]);
        }
    }
    while (stack.GetOperationsSize() != 0) {
        int num2 = stack.element_pop_back();
        int num1 = stack.element_pop_back();
        int res = doOperation(num1, num2, stack.operation_pop_back());
        stack.element_push_back(res);

    }
    return stack.GetLastElement();
}

vector<string> getwords(char str[]) {
    vector<string> words;
    char* pch = strtok(str, " "); //во втором параметре указаны разделители (пробел, запятая, точка)
    while (pch != NULL) //пока есть лексемы
    {
        words.push_back(pch);
        pch = strtok(NULL, " ");
    }
    return words;
}

int doOperation(int num1, int num2, char operation) {
    switch (operation)
    {
    case '+':
        return num1 + num2;
        break;
    case '-':
        return num1 - num2;
        break;
    case '*':
        return num1 * num2;
        break;
    case '/':
        return num1 / num2;
        break;
    }
}

void calcBrack(Stack& stack) {
    if (stack.GetLastOperation() == '(') {
        stack.operation_pop_back();
    }
    else {
        int num2 = stack.element_pop_back();

        int num1 = stack.element_pop_back();
        int result = doOperation(num1, num2, stack.operation_pop_back());
        stack.element_push_back(result);
        calcBrack(stack);
    }
}



bool IsOper(char op) {
    switch (op)
    {
    case '+':
        return true;
        break;
    case '-':
        return true;
        break;
    case '*':
        return true;
        break;
    case '/':
        return true;
        break;
    default:
        return false;
        break;
    }

}


int getRang(char oper) {
    if (oper == '+' || oper == '-') return 1;
    if (oper == '/' || oper == '*') return 2;
    else return 0;
}
