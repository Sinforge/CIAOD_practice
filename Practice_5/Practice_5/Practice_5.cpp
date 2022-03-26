

#include <iostream>
using namespace std;
struct node {
    char ch;
    unsigned int count = 0;
    node* ptr_next = NULL;
};

void add(char ch, node*& END, node*& LIST);

void insert_last_in_list(node*& LIST1, node* END1, node* LIST2);

bool compare_list(node* LIST1, node* LIST2);

void delete_digits(node*& LIST2);

void print_list(node* LIST);


int main()
{
    setlocale(LC_ALL, "");
    int test;
    node* LIST1 = new node;
    //Завел указатели на последние элементы списков для уменьшения сложности алгоритма вставки нового элемента
    node* END1 = LIST1, *LIST2 = new node, *END2 = LIST2;  
    
    char ch;
    int  n1, n2;
    //Заполнение списков:
    cout << "Размер списка 1\n";
    cin >> n1;
    cout << "Первый список:\n";
    for (int i = 0; i < n1; i++) {
        cin >> ch;
        add(ch, END1, LIST1);
    }
    cout << "Размер списка 2\n";
    cin >> n2;
    cout << "Второй список:\n";
    for (int i = 0; i < n2; i++) {
        cin >> ch;
        add(ch, END2, LIST2);
    }

    cout << "Введите номер функции, которую хотите проверить: \n1 - Сравнение списков\n2 -Вставить последний элемент одного списка во второй\n3 - Удалить узлы с цифрами из второго списка\n ";
    cin >> test;



    switch (test) {
    case 1:
        //Сравнение списков
        cout << "списки равны - " << (bool)compare_list(LIST1, LIST2) << " (0 - false, 1 - true)" << endl;
        break;
    case 2:
        //вставить последний элемент одного списка во второй
        cout << "\n\nВставить последний элемент второго списка в первый:\n\n";
        insert_last_in_list(LIST1, END1, LIST2);
        print_list(LIST1);
        cout << endl;
        break;
    case 3:
        //Удалить из списка 2 цифры
        cout << "\n\nУдалить из списка 2 цифры\n\n";
        delete_digits(LIST2);
        cout << endl;
        print_list(LIST2);
        break;
    }

}
void add(char ch, node*& END, node*& LIST) {
    node* n = new node;
    LIST->count++;
    n->ch = ch;
    END->ptr_next = n;
    END = n;
}

void print_list(node* LIST) {
    node* tmp = LIST->ptr_next;
    while (tmp != NULL) {
        cout << tmp->ch << " ";
        tmp = tmp->ptr_next;
    }
}

void insert_last_in_list(node*& LIST1, node* END1, node* LIST2) {
    node* tmp1 = LIST2;
    LIST1->count++;
    while (tmp1->ptr_next != NULL) {
        tmp1 = tmp1->ptr_next;
    }
    add(tmp1->ch, END1, LIST1);
}

bool compare_list(node* LIST1, node* LIST2) {
    node* tmp1 = LIST1, * tmp2 = LIST2;
    if (LIST1->count == LIST2->count) {
        while (tmp1->ptr_next != NULL) {
            if (tmp1->ch != tmp2->ch) {
                return false;
            }
            tmp1 = tmp1->ptr_next;
            tmp2 = tmp2->ptr_next;
        }
    }
    else {
        return false;
    }
    return true;
}

void delete_digits(node*& LIST2) {
    node* tmp1 = LIST2->ptr_next;
    node* prev = LIST2;
    while (tmp1 != NULL) {
        if (tmp1->ch == '0' || tmp1->ch == '1' || tmp1->ch == '2' || tmp1->ch == '3' || tmp1->ch == '4' || tmp1->ch == '5' || tmp1->ch == '6' || tmp1->ch == '7' || tmp1->ch == '8' || tmp1->ch == '9') {
            prev->ptr_next = tmp1->ptr_next;
            tmp1 = tmp1->ptr_next;
        }
        else {
            prev = tmp1;
            tmp1 = tmp1->ptr_next;
            if (tmp1 == NULL) {
                break;
            }
        }
    }
}
