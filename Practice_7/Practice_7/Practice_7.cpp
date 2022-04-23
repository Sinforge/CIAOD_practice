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

struct Stack {
    vector<int> elements;
    vector<char> operations;
    int last_el = -1;
    int last_op = -1;
};


vector<string> getwords(char str[]);
int calc(char str[]);
int doOperation(int num1, int num2, char operation);
void calcBrack(Stack& stack);
bool IsOper(char op);
int getRang(char oper);




int main()
{
    char s[255];
    gets_s(s);
    int res = calc(s);
    cout << res;

}

int calc(char str[]) {
    Stack stack;
    vector<string> symbols = getwords(str);
    for (int i = 0; i < symbols.size(); i++) {
        if (isdigit(symbols[i][0])) {
            if (stack.elements.size() == 0) {
                stack.elements.push_back(stoi(symbols[i]));
                stack.last_el++;
            }
            else if (stack.operations[stack.last_op] == '(') {
                stack.elements.push_back(stoi(symbols[i]));
                stack.last_el++;
            }
            else if (stack.operations[stack.last_op] == '/' || stack.operations[stack.last_op] == '*') {
                int res1 = stack.elements[stack.last_el];
                stack.elements.pop_back();
                stack.last_el--;
                int res2 = stoi(symbols[i]);
                stack.elements.push_back(doOperation(res1, res2, stack.operations[stack.last_op]));
                stack.last_el++;
                stack.operations.pop_back();
                stack.last_op--;
            }
            else {
                stack.elements.push_back(stoi(symbols[i]));
                stack.last_el++;
            }
        }
        else if (symbols[i] == "(" || symbols[i] == ")") {
            if (symbols[i] == "(") {
                stack.operations.push_back(symbols[i][0]);
                stack.last_op++;
            }
            else {
                calcBrack(stack);
            }
        }
        else {
            if (stack.operations.size() >= 1) {
                if (getRang(symbols[i][0]) == getRang(stack.operations[stack.last_op])) {
                    int num2 = stack.elements[stack.last_el];
                    stack.elements.pop_back();
                    stack.last_el--;
                    int num1 = stack.elements[stack.last_el];
                    stack.elements.pop_back();
                    stack.last_el--;
                    int result = doOperation(num1, num2, stack.operations[stack.last_op]);
                    stack.operations.pop_back();
                    stack.last_op--;
                    stack.elements.push_back(result);
                    stack.last_el++;
                }
            }
            stack.operations.push_back(symbols[i][0]);
            stack.last_op++;
        }
    }
    while (stack.operations.size() != 0) {
        int num2 = stack.elements[stack.last_el];
        stack.elements.pop_back();
        stack.last_el--;
        int num1 = stack.elements[stack.last_el];
        stack.elements.pop_back();
        stack.last_el--;
        int res = doOperation(num1, num2, stack.operations[stack.last_op]);
        stack.operations.pop_back();
        stack.last_op--;
        stack.elements.push_back(res);
        stack.last_el++;

    }
    int END = stack.elements[0];
    return END;
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
    if (stack.operations[stack.last_op] == '(') {
        stack.operations.pop_back();
        stack.last_op--;
    }
    else {
        int num2 = stack.elements[stack.last_el];
        stack.elements.pop_back();
        stack.last_el--;
        int num1 = stack.elements[stack.last_el];
        stack.elements.pop_back();
        stack.last_el--;
        int result = doOperation(num1, num2, stack.operations[stack.last_op]);
        stack.operations.pop_back();
        stack.last_op--;
        stack.elements.push_back(result);
        stack.last_el++;
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
