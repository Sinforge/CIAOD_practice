#include <iostream>
#include <vector>
using namespace std;


void fill_massive(vector<int>& vector);
void print_massive(vector <int> vector);
int count_digits(int n);
bool number_is_even1(int num);
void insert_1(vector <int>& vector, int n);
void delete_even_numbers(vector <int>& vector);
int find_max(vector <int> vector);


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
	vector <int> a(num);
	cout << "Введите элементы массива\n";
	fill_massive(a);
	cout << "Пользовательское меню: \n1 - Вывод массива\n2-Вставить число\n3-Удалить четные числа\n4-Найти максимальное на четной позиции\n5-Ввод массива\n0-для выхода\n";
	cin >> choice;
	while (choice) {
		switch (choice) {
		case 1:
			print_massive(a);
			cout << "\n";
			break;
		case 2:
			cout << "\nВведите значение которое хотите вставить: \n ";
			cin >> ins;
			insert_1(a, ins);
			cout << "\n Массив с вставленным значением: ";
			print_massive(a);
			cout << "\n";
			break;
		case 3:
			cout << "\nМассив без четных чисел\n";
			delete_even_numbers(a);
			print_massive(a);
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
			a.resize(num);
			cout << "Введите элементы массива\n";
			fill_massive(a);
		}



		cout << "Пользовательское меню: \n1 - Вывод массива\n2-Вставить число\n3-Удалить четные числа\n4-Найти максимальное на четной позиции\n5-Ввод массива\n0-для выхода\n";
		cin >> choice;

	}




}
void fill_massive(vector<int>& vector) { // Ввод значений вектора
	for (int i = 0; i < vector.size(); i++) {
		cin >> vector[i];
	}
}





void print_massive(vector <int> vector) {// Вывод вектора
	for (int i = 0; i < vector.size(); i++) {
		cout << vector[i] << " ";
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

bool number_is_even1(int num) { //Проверка на четность
	if (num % 2 == 0) {
		return true;
	}
	else {
		return false;
	}
}


void insert_1(vector <int>& vector, int n) { // Вставка значения
	int index = -1;
	for (int i = 0; i < vector.size(); i++) {
		if (number_is_even1(count_digits(vector[i]))) {
			index = i;
			break;
		}
	}
	if (index == -1) {
	}
	else {
		vector.insert(vector.begin() + index, 1, n);
	}

}
void delete_even_numbers(vector <int>& vector) { // Удалить четные числа
	for (int i = 0; i < vector.size(); i++) {
		if (number_is_even1(vector[i])) {
			vector.erase(vector.begin() + i);
			i--;
		}
	}

}
int find_max(vector <int> vector) { // Найти максимальное среди чисел, расположенных на четных местах
	int max = vector[0];
	for (int i = 0; i < vector.size(); i += 2) {
		if (max < vector[i]) {
			max = vector[i];
		}
	}
	return max;
}