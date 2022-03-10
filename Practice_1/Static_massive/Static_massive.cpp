#include <iostream>
#include <locale>
using namespace std;
int mas[1000], M = 1000;

void fill_massive(int* a, int b);
void print_massive(int* a, int b);
int count_digits(int n);
int insert1(int* a, int& b, int n);
bool number_is_even(int num);
void delete_even_numbers(int* a, int& b);
int find_max(int* a, int b);



int main() {
	setlocale(LC_ALL, "Russian");
	int num, ins;
	int insert;
	int* a = &mas[1000];
	int choice; // Переменная для пользовательского ввода
	cout << "Добро пожаловать в практическую работу номер 1, выполнил студент группы ИКБО-03-21, Власов В.В., Вариант-5\n";
	cout << "Введите количество элементов в массиве(не больше 1000): ";
	cin >> num;
	if (num <= 0 || num > 1000) {
		cout << "\nВведено неправильное значение для количества элементов массива\n";
		return -1;
	}
	cout << "Введите элементы массива\n";
	fill_massive(a, num);
	cout << "Пользовательское меню: \n1 - Вывод массива\n2-Вставить число\n3-Удалить четные числа\n4-Найти максимальное на четной позиции\n5-Ввод массива\n0-для выхода\n";
	cin >> choice;
	while (choice) {
		switch (choice) {
		case 1:
			print_massive(a, num);
			cout << "\n";
			break;
		case 2:
			cout << "\nВведите значение которое хотите вставить: \n ";
			cin >> ins;
			insert = insert1(a, num, ins);
			if (insert == -1) {
				cout << "\nВ массив не будет вставлено значение, так как в нем отсутствует элемент с четным количеством цифр\n";
			}
			else if (insert == -2) {
				cout << "\nВ массив не будет вставлено значение, так как при вставке значения в массив его размер будет больше 1000\n";

			}
			else {
				cout << "\n Массив с вставленным значением: ";
				print_massive(a, num);
				cout << "\n";
			}
			break;
		case 3:
			cout << "\nМассив без четных чисел\n";
			delete_even_numbers(a, num);
			print_massive(a, num);
			cout << "\n";
			break;
		case 4:
			cout << "\n Максимальное значение в массиве: " << find_max(a, num) << endl;
			break;
		case 5:
			cout << "Введите количество элементов в массиве(не больше 1000): ";
			cin >> num;
			if (num <= 0 || num > 1000) {
				cout << "\nВведено неправильное значение для количества элементов массива\n";
				return -1;
			}
			cout << "Введите элементы массива\n";
			fill_massive(a, num);
		}



		cout << "Пользовательское меню: \n1 - Вывод массива\n2-Вставить число\n3-Удалить четные числа\n4-Найти максимальное на четной позиции\n5-Ввод массива\n0-для выхода\n";
		cin >> choice;

	}
}



void fill_massive(int* a, int b) { //Ввод массива
	for (int i = 0; i < b; i++) {
		cin >> a[i];
	}

}


void print_massive(int* a, int b) { // Вывод массива
	for (int i = 0; i < b; i++) {
		cout << a[i] << " ";
	}

}


int count_digits(int n) { // Подсчет цифр в числе
	int count = 0;
	while (n != 0) {
		count++;
		n = n / 10;
	}
	return count;

}

int insert1(int* a, int& b, int n) { // Вставка значения
	int index = -1, temp0, temp1;
	for (int i = 0; i < b; i++) {
		if (number_is_even(count_digits(a[i]))) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		return -1;
	}
	else if (index != -1 && b == 1000) {
		return -2;
	}
	else {
		temp0 = a[index];
		a[index] = n;
		for (int j = index + 1; j < b + 1; j++) {
			temp1 = a[j];
			a[j] = temp0;
			temp0 = temp1;
		}
		b++;
		return 0;
	}
}

bool number_is_even(int num) { //Проверка на четность
	if (num % 2 == 0) {
		return true;
	}
	else {
		return false;
	}
}
void delete_even_numbers(int* a, int& b) { // Удаление четных чисел
	for (int i = 0; i < b; i++) {
		if (number_is_even(a[i])) {
			for (int j = i; j < b - 1; j++) {
				a[j] = a[j + 1];
			}
			b--;
			i--;
		}
	}

}


int find_max(int* a, int b) { // Поиск максимального на четных местах
	int max = a[0];
	for (int i = 0; i < b; i += 2) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	return max;
}