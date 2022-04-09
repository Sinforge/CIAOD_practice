

#include <iostream>
using namespace std;

struct stack { // стек( информационная часть узла - a, добавил просто для наглядности; 
    int a; // информационная часть узла, добавил просто для наглядности; 
    stack* next = NULL;// указатель на следующий элемент - next
};


float average(float* mas, int start, int end);//Рекурсивная функция подсчета среднего арифм.

void create_stack(stack* last_elem, int size);// Создание стек, состоящего из n узлов
void check_stack(stack* STACK); //Вывод стека на экран
//Вариант-5
int main()
{
    setlocale(LC_ALL, "");
    //задание 1
    float* mas;
    int size;
    cout << "введите размер массива: ";
    cin >> size;
    mas = new float[size];
    for (int i = 0; i < size; i++) {
        cin >> mas[i];
    }
    cout << "average:" <<  average(mas, 0, size) << endl;
    //задание 2
    int size_stack;
    stack* NewStack = new stack();
    cout << "\nВведите кол-во элементов в стеке: ";
    cin >> size_stack;
    create_stack(NewStack, size_stack);
    check_stack(NewStack);

}


float average(float* mas, int start, int end) {//Рекурсивная функция подсчета среднего арифм.
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

void create_stack(stack* last_elem, int size) {// Создание стек, состоящего из n узлов
    static unsigned int count = 0;
    if (size > 0) {
        count++;
        stack* node = new stack();
        last_elem->next = node;
        last_elem->a = size;
        create_stack(node, size - 1);
    }
    else {
        cout <<"Глубина рекурсии " <<  count << endl;
    }

}
void check_stack(stack* STACK) {
    stack* node = STACK->next;
    while (node != NULL) {
        cout << node->a << " ";
        node = node->next;
    }
}
