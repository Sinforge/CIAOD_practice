// Practice_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;


void fill_random_vector(vector<int>& mas) {
    for (int i = 0; i < mas.size(); i++) {
        mas[i] = rand();
    }
}
void fill_handwrite_vector(vector<int>& mas) {
    cout << "\nВведите значения массива: ";
    for (int i = 0; i < mas.size(); i++) {
        cin >> mas[i];
    }
}
void print_vector(vector<int> mas) {
    cout << "\nМассив(размер = " << mas.size() << 
        "): ";
    for (int i = 0; i < mas.size(); i++) {
        cout << mas[i] << " ";
    }
}
int insert_sort(vector<int>& mas) {
    unsigned int start_time = clock();
    for (int i = 1; i < mas.size(); i++) {
        int x = mas[i];
        int j = i;
        while (j > 0 && mas[j - 1] > x) {
            mas[j] = mas[j - 1];
            j--;
        }
        mas[j] = x;
    }
    unsigned int end_time = clock();
    return end_time - start_time;
}
int Shell_sort(vector<int> & mas) {
    unsigned int start_time = clock();
    int h = 1;
    while (h < mas.size()/2) {
        h = 2 * h + 1;
    }
    while (h > 0) {
        for (int i = h; i < mas.size(); i++) {
            for (int j = i; j >= h; j -= h) {
                if (mas[j] < mas[j - h]) {
                    swap(mas[j], mas[j - h]);
                }
                else {
                    break;
                 }
                }
            }
        h = (h - 1) / 2;
        }
    unsigned int end_time = clock();
    return (end_time - start_time);
}


vector<int> merge(vector<int> v1, vector<int> v2) {
    vector<int> result;
    int it1 =0 , it2 =0 ;
    while (true) {
        if (it1 == v1.size()) {
            for (int i = it2; i < v2.size(); i++) {
                result.push_back(v2[i]);
            }
            break;
        }
        if (it2 == v2.size()) {
            for (int i = it1; i < v1.size(); i++) {
                result.push_back(v1[i]);
            }
            break;
        }
        if (v1[it1] <= v2[it2]) {
            result.push_back(v1[it1]);
            it1++;
        }
        else {
            result.push_back(v2[it2]);
            it2++;
        }
    }
    return result;
}


//Естественное слияние
int Natural_Merge_sort(vector<int> &mas) {
    unsigned int start = clock();
    vector<vector<int>> sub_mas(1);
    int a = 0; //номер подпоследовательности
    sub_mas[0].push_back(mas[0]);

    //Разделяем на подпоследовательности
    for (int i = 1; i < mas.size(); i++) {
        if (mas[i] >= mas[i - 1]) {
            sub_mas[a].push_back(mas[i]);
        }
        else {
            vector<int> subseq;
            sub_mas.push_back(subseq);
            a++;
            sub_mas[a].push_back(mas[i]);
        }
    }
    while (sub_mas.size() != 1) {
        vector<vector<int>> s;
        for (int i = 0; i < sub_mas.size() - 1; i += 2) {
            s.push_back(merge(sub_mas[i], sub_mas[i + 1]));
        }
        sub_mas = s;
        

    }
    mas = sub_mas[0];
    unsigned int end = clock();
    return end - start;
}




int main()
{
    unsigned int start;

    unsigned int end;
    setlocale(LC_ALL, "");
    vector<int> mas;
    int size, menu;
    cout << "Пользовательское меню:\n0- Выход из программы\n1- Установить размер массива;\n2- Заполнить массив вручную;\n3 - Заполнить массив псевдорандомными числами;\n4-Вывести массив;\n5-Сортировка вставками;\n6-Сортировка Шелла со смещения Кнута(2 способ)\n7-Естественное слияние;\n";
    cin >> menu;
    while (menu) {
        switch (menu) {
        case 1:
            cout << "Введите размер массива: ";
            cin >> size;
            mas = vector<int>(size);
            break;
        case 2:
            fill_handwrite_vector(mas);
            break;
        case 3:
            fill_random_vector(mas);
            break;
        case 4:
            print_vector(mas);
            break;
        case 5:
            cout << "Время выполнения :" << insert_sort(mas) << " мс\n";
            break;
        case 6:
            cout << "Время выполнения :" << Shell_sort(mas) << " мс\n";
            break;
        case 7:
            cout << "Время выполнения :" << Natural_Merge_sort(mas) << " мс\n";
            break;
        }

        cout << "\n\nПользовательское меню:\n0- Выход из программы\n1- Установить размер массива;\n2- Заполнить массив вручную;\n3 - Заполнить массив псевдорандомными числами;\n4-Вывести массив;\n5-Сортировка вставками;\n6-Сортировка Шелла со смещения Кнута(2 способ)\n7-Естественное слияние;\n";
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
