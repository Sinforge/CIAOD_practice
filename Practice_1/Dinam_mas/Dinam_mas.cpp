#include <iostream>
#include <cstdlib>
using namespace std;


void fill_massive1(int* a, int n);


void print_massive1(int* a, int n);
int count_digits1(int n);

int* insert2(int* a, int n, int& b);

bool number_is_even1(int num);

int* delete_even_numbers1(int* a, int& b);
int find_max(int* a);
int main() {
	setlocale(LC_ALL, "Russian");
	int num, ins;
	int choice; // Переменная для пользовательского ввода
	cout << "Добро пожаловать в практическую работу номер 1, выполнил студент группы ИКБО-03-21, Власов В.В., Вариант-5\n";
	cout << "Введите количество элементов в массиве: ";
	cin >> num;
	if (num <= 0) {
		cout << "\nВведено неправильное значение для количества элементов массива\n";
		return -1;
	}
	int* a = new int[num];
	cout << "Введите элементы массива\n";
	fill_massive1(a, num);
	cout << "Пользовательское меню: \n1 - Вывод массива\n2-Вставить число\n3-Удалить четные числа\n4-Найти максимальное на четной позиции\n5-Ввод массива\n0-для выхода\n";
	cin >> choice;
	while (choice) {
		switch (choice) {
		case 1:
			print_massive1(a, num);
			cout << "\n";
			break;
		case 2:
			cout << "\nВведите значение которое хотите вставить: \n ";
			cin >> ins;
			a = insert2(a, ins, num);
			cout << "\n Массив с вставленным значением: ";
			print_massive1(a, num);
			cout << "\n";
			break;
		case 3:
			cout << "\nМассив без четных чисел\n";
			a = delete_even_numbers1(a, num);
			print_massive1(a, num);
			cout << "\n";
			break;
		case 4:
			cout << "\n Максимальное значение в массиве: " << find_max(a) << endl;
			break;
		case 5:
			cout << "Введите количество элементов в массиве: ";
			cin >> num;
			if (num <= 0 || num > 1000) {
				cout << "\nВведено неправильное значение для количества элементов массива\n";
				return -1;
			}
			a = new int[num];
			cout << "Введите элементы массива\n";
			fill_massive1(a, num);
		}



		cout << "Пользовательское меню: \n1 - Вывод массива\n2-Вставить число\n3-Удалить четные числа\n4-Найти максимальное на четной позиции\n5-Ввод массива\n0-для выхода\n";
		cin >> choice;

	}
}



void fill_massive1(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

}




void print_massive1(int* a) {
	for (int i = 0; i < sizeof(a); i++) {
		cout << a[i] << " ";
	}

}

int count_digits1(int n) { // Подсчет цифр в числе
	int count = 0;
	while (n != 0) {
		count++;
		n = n / 10;
	}
	return count;
}

int* insert2(int* a, int n, int& b) {
	int index = -1;
	b;
	int* new_massive = new int[b + 1];
	for (int i = 0; i < b; i++) {
		if (number_is_even1(count_digits1(a[i]))) {
			index = i;
			break;
		}
		new_massive[i] = a[i];
	}
	if (index == -1) {
		return a;
		delete[] new_massive;
	}
	else {
		new_massive[index] = n;
		for (int j = index + 1; j < b + 1; j++) {
			new_massive[index] = a[j];
		}
		b++;
		delete[] a;
	}
}

bool number_is_even1(int num) { //Проверка на четность
	if (num % 2 == 0) {
		return true;
	}
	else {
		return false;
	}
}


int* delete_even_numbers1(int* a, int& b) {
	int count = 0;
	for (int i = 0; i < b; i++) {
		if (!number_is_even1(a[i])) {
			count++;
		}
	}
	if (count == 0) {
		return a;
	}
	else {
		int* new_mas = new int[count];
		int j = 0;
		for (int i = 0; i < b; i++) {
			if (!number_is_even1(a[i])) {
				new_mas[j] = a[i];
				j++;
			}
		}
		delete[] a;
		b = count;
		return new_mas;
	}

}
int find_max(int* a) {
	int max = a[0];
	for (int i = 0; i < sizeof(a); i += 2) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	return max;
}