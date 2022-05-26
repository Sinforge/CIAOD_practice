// Pract_9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Patient {
    int card_id = 0;
    int illness_id = 0;
    string doctor_surname = "Doctor";
    void print_info() {
        cout << card_id << " " << illness_id << " " << doctor_surname << endl;
    }

};


int Linear_Search(int card_id, vector<Patient> table) {
    int start = clock();
    for (int i = 0; i < table.size(); i++) {
        if (table.at(i).card_id == card_id) return i;
    }
    int end = clock();
    cout << "Время поиска: " << end - start << endl;
    return -1;
}
int Barrier_Search(int card_id, vector<Patient> table) {
    int start = clock();
    if (table.back().card_id == card_id) return table.size() - 1;
    table.back().card_id = (card_id);
    int iter = 0;
    while (true) {
        if (table[iter].card_id == card_id) {break;}
        iter++;
    }
    int end = clock();
    cout << "Время поиска: " << end - start << endl;

    return iter == table.size() - 1 ? -1 : iter;
}
void random_input_table(vector<Patient>& table) {
    for (int i = 0; i < table.size(); i++) {
        table.at(i).card_id = rand();
        table.at(i).illness_id = rand();
    }
}
void handwrite_input(vector<Patient>& table) {
    for (int i = 0; i < table.size(); i++) {
        cin >> table.at(i).card_id;
        cin >> table.at(i).illness_id;
        cin >> table.at(i).doctor_surname;
    }
}
void print_table(vector<Patient> table) {
    for (int i = 0; i < table.size(); i++) {
        table[i].print_info();
    }
}

int interpolationSearch(vector<Patient>table, int card_id) {
    int pos;
    int low = 0;
    int high = table.size() - 1;
    int start = clock();
    int count = 0;
    while (table[low].card_id <= card_id && table[high].card_id >= card_id && low <= high) {
        count++;
        if (low == high) {
            if (table[low].card_id == card_id) return low;
            return -1;
        }
        pos = low + ((high - low) /(table[high].card_id - table[low].card_id)) * (card_id - table[low].card_id);
        if (table[pos].card_id == card_id) {
            return pos;
        }
        if (table[pos].card_id < card_id) {
            low = pos + 1;
        }
        else {
            high = pos - 1;
        }
       

        
    }
    int end = clock();
    cout << "Время поиска: " << end - start << endl << "Кол-во операций: " << count;
    return -1;
}

void sort_table_by_card(vector<Patient>& table) {
    int h = 1;
    while (h < table.size() / 2) {
        h = 2 * h + 1;
    }
    while (h > 0) {
        for (int i = h; i < table.size(); i++) {
            for (int j = i; j >= h; j -= h) {
                if (table[j].card_id < table[j - h].card_id) {
                    swap(table[j], table[j - h]);
                }
                else {
                    break;
                }
            }
        }
        h = (h - 1) / 2;
    }
}
int main()
{
    setlocale(LC_ALL, "");
    vector<Patient> table;
    int size;
    int start, end;
    cout << sizeof(Patient);
    cout << "Введите размер таблицы\n";
    cin >> size;
    table = vector<Patient>(size);
    int menu;
    int card;
    cout << "Пользовательское меню:\n0- Выход из программы\n1- Установить размер таблицы;\n2- Вывод таблицы;\n3 - Линейный поиск;\n4-Поиск с барьером;\n5-Интерполяционный поиск;\n6-Рандомное заполнение таблицы\n";
    cin >> menu;
    while (menu) {
        switch (menu) {
        case 1:
            cout << "Введите размер таблицы\n";
            cin >> size;
            table = vector<Patient>(size);
            break;

        case 2:
            print_table(table);
            break;
        case 3:
            cout << "Введите номер карты\n";
            cin >> card;
            cout << Linear_Search(card, table) << endl;
            break;
        case 4:
            cout << "Введите номер карты\n";
            cin >> card;
            cout << Barrier_Search(card, table) << endl;
            end = clock();
            break;

        case 5:
            cout << "Введите номер карты\n";
            cin >> card;
            cout << interpolationSearch(table, card) << endl;
            break;
        case 6:
            random_input_table(table);
            break;
        case 7:
            sort_table_by_card(table);
            break;
        case 8:
            handwrite_input(table);
            break;
        }
        cout << "\nПользовательское меню:\n0- Выход из программы\n1- Установить размер таблицы;\n2- Вывод таблицы;\n3 - Линейный поиск;\n4-Поиск с барьером;\n5-Интерполяционный поиск;\n6-Рандомное заполнение таблицы\n";
        cin >> menu;
    }
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
