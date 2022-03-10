
#include <iostream>
#include <time.h>
using namespace std;

void fill_matrix_by_hand(int**& matrix, int rows, int cols);

void multiplic_matrix(int**& matrix_res, int** matrix1, int** matrix2, int row1, int col1, int row2, int col2);

void fill_matrix_random(int**& matrix, int rows, int cols);

void print_matrix(int** matrix, int rows, int cols);

bool check(int col1, int row2);

int main() {
	setlocale(LC_ALL, "");
	int menu;
	int row1, col1;
	int** matrix1, ** matrix2, ** matrix3;
	int row2, col2;
	cout << "Введите количество строк в матрице 1:\n";
	cin >> row1;
	cout << "Введите количество столбцов в матрице 1:\n";
	cin >> col1;
	cout << "Введите количество строк в матрице 2:\n";
	cin >> row2;
	cout << "Введите количество столбцов в матрице 2:\n";
	cin >> col2;
	if (row1 < 1 || col1 < 1 || row2 < 1 || col2 < 1) {
		cout << "Было введено некорректное значение\n";
		return 0;
	}
	if (!check(col1, row2)) {
		cout << "Нельзя умножить 1-ю матрицу на 2-ю\n";
		return 0;
	}
	matrix1 = new int* [row1];
	matrix2 = new int* [row2];

	cout << "Пользовательское меню:\n0- Для выхода\n1-Заполнить первый массив рандомными числами\n2-Заполнить первый массив вручную\n3-Заполнить второй массив рандомными числами\n4-Заполнить второй массив вручную\n5-Вывести матрицу 1\n6-Вывести матрицу 2\n";
	cin >> menu;


	while (menu) {


		switch (menu) {
		case 1:
			fill_matrix_random(matrix1, row1, col1);
			break;

		case 2:
			fill_matrix_by_hand(matrix1, row1, col1);
			break;
		case 3:
			fill_matrix_random(matrix2, row2, col2);
			break;

		case 4:
			fill_matrix_by_hand(matrix2, row2, col2);
			break;

		case 5:
			print_matrix(matrix1, row1, col1);
			break;
		case 6:
			print_matrix(matrix2, row2, col2);
			break;
		}
		cout << "Пользовательское меню:\n0- Для выхода\n1-Заполнить первый массив рандомными числами\n2-Заполнить первый массив вручную\n3-Заполнить второй массив рандомными числами\n4-Заполнить второй массив вручную\n5-Вывести матрицу 1\n6-Вывести матрицу 2\n";
		cin >> menu;
	}
	multiplic_matrix(matrix3, matrix1, matrix2, row1, col1, row2, col2);
	print_matrix(matrix3, row1, col2);



}

void fill_matrix_by_hand(int**& matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
		cout << "\nВведите элементы " << i + 1 << " строки: ";
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}

}
void multiplic_matrix(int**& matrix_res, int** matrix1, int** matrix2, int row1, int col1, int row2, int col2) {
	int row3 = row1;
	int col3 = col2;
	matrix_res = new int* [row3];
	int summa = 0;
	for (int i = 0; i < row3; i++) {
		matrix_res[i] = new int[col3];
		for (int j = 0; j < col3; j++) {
			summa = 0;
			for (int k = 0; k < col1; k++) {
				summa += matrix1[i][k] * matrix2[k][j];
			}
			matrix_res[i][j] = summa;
		}
	}
}



void fill_matrix_random(int**& matrix, int rows, int cols) {
	srand(0);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = rand() % 100;
		}
	}

}

void print_matrix(int** matrix, int rows, int cols) {
	cout << "Матрица:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

bool check(int col1, int row2) {
	if (col1 == row2) {
		return true;
	}
	else {
		return false;
	}
}