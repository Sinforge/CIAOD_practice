

#include <iostream>
using namespace std;

struct stack {
    int a;
    stack* next;
};


float average(float * mas, int start, int end) {
    static unsigned int count = 0;
    if (end != start) {
        count++;
        return mas[start] / end + average(mas, start + 1, end);
    }
    else {
        cout << "Глубина рекурсии:" << count << endl;
        return 0;
    }
}

void create_stack(stack* last_elem, int size) {
    static unsigned int count = 0;
    if (size > 0) {
        count++;
        stack* node = new stack();
        last_elem->next = node;
        create_stack(node, size - 1);
    }
    else {
        cout << count << endl;
    }

}
//Вариант-5
int main()
{
    setlocale(LC_ALL, "");
    //Задание 1
    float* mas;
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    mas = new float[size];
    for (int i = 0; i < size; i++) {
        cin >> mas[i];
    }
    cout << "Average:" <<  average(mas, 0, size) << endl;
    //Задание 2
    int size_stack;
    stack* NewStack = new stack();
    cin >> size_stack;
    create_stack(NewStack, size_stack);

}
