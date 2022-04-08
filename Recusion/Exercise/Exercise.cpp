// Exercise.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

int main()
{
    setlocale(LC_ALL, "");
    /*float* mas;
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    mas = new float[size];
    for (int i = 0; i < size; i++) {
        cin >> mas[i];
    }
    cout << "Average:" <<  average(mas, 0, size) << endl;
    */
    int size_stack;
    stack* NewStack = new stack();
    cin >> size_stack;
    create_stack(NewStack, size_stack);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
