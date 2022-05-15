
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <time.h>
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
    double start_time = clock();
    for (int i = 1; i < mas.size(); i++) {
        int x = mas[i];
        int j = i;
        while (j > 0 && mas[j - 1] > x) {
            mas[j] = mas[j - 1];
            j--;
        }
        mas[j] = x;
    }
    double end_time = clock();
    return end_time - start_time;
}
int Shell_sort(vector<int>& mas) {
    unsigned int start_time = clock();
    int h = 1;
    while (h < mas.size() / 2) {
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


void merge(vector<int>& source, vector<int>& target, int startleft, int startright, int endright) {
    int leftpos = startleft;
    int rightpos = startright;
    int targetpos = startleft;


    while (leftpos < startright && rightpos < endright) {
        int leftValue = source[leftpos];
        int rightValue = source[rightpos];
        if (leftValue <= rightValue) {
            target[targetpos++] = leftValue;
            leftpos++;
        }
        else {
            target[targetpos++] = rightValue;
            rightpos++;
        }
    }

    while (leftpos < startright) {
        target[targetpos++] = source[leftpos++];
    }
    while (rightpos < endright) {
        target[targetpos++] = source[rightpos++];
    }
}


void NaturalMergeSort(vector<int>& mas) {
    vector<int> segments = vector<int>(mas.size() + 1);

    int segCount = 0;
    segments[0] = 0;

    //Определение подпоследовательностей
    for (int i = 1; i <= mas.size(); i++) {
        if (i == mas.size() || mas[i] < mas[i - 1]) {
            segments[++segCount] = i;
        }
    }

    vector<int> from = mas;
    vector<int> to = vector<int>(mas.size());
    while (segCount > 1) {
        int new_segCount = 0;
        for (int i = 0; i < segCount - 1; i += 2) {
            merge(from, to, segments[i], segments[i + 1], segments[i + 2]);
            segments[new_segCount++] = segments[i];
        }


        if (segCount % 2 == 1) {
            int lastSeg = segments[segCount - 1];
            for (int i = lastSeg; i < mas.size(); i++) {
                to[i] = from[i];
            }
            segments[new_segCount++] = lastSeg;
        }

        segments[new_segCount] = mas.size();
        segCount = new_segCount;

        vector<int> help = from;
        from = to;
        to = help;
    }
    if (from != mas) {
        for (int i = 0; i < mas.size(); i++) {
            mas[i] = from[i];
        }
    }

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
            start = clock();
            NaturalMergeSort(mas);
            end = clock();
            cout << "Время выполнения :" << end -start << " мс\n";
            break;
        case 8:
            reverse(mas.begin(), mas.end());
            break;
        }
        

        cout << "\n\nПользовательское меню:\n0- Выход из программы\n1- Установить размер массива;\n2- Заполнить массив вручную;\n3 - Заполнить массив псевдорандомными числами;\n4-Вывести массив;\n5-Сортировка вставками;\n6-Сортировка Шелла со смещения Кнута(2 способ)\n7-Естественное слияние;\n";
        cin >> menu;
    }
}
