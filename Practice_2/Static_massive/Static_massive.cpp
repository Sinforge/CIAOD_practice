
#include <iostream>
#include <time.h>
#include <locale>
using namespace std;
int const rows1 = 20, cols1 = 20;

void fill_matrix_by_hand(int matrix[][cols1], int rows, int cols);

void multiplic_matrix(int matrix_res[][cols1], int matrix1[][cols1], int matrix2[][cols1], int row1, int col1, int row2, int col2);

void fill_matrix_random(int matrix[][cols1], int rows, int cols);

void print_matrix(int matrix[][cols1], int rows, int cols);

bool check(int col1, int row2);
int main() {
	setlocale(LC_ALL, "");
	int matrix1[rows1][cols1];
	int matrix3[rows1][cols1];
	int matrix2[rows1][cols1];
	int menu;
	int row1, col1;
	int row2, col2;
	cout << "Введите количество строк в матрице 1:\n";
	cin >> row1;
	cout << "Введите количество столбоцов в матрице 1:\n";
	cin >> col1;
	cout << "Введите количество строк в матрице 2:\n";
	cin >> row2;
	cout << "Введите количество столбоцов в матрице 2:\n";
	cin >> col2;
	if (row1 < 1 || row1 > 20 || col1 < 1 || col1 > 20 || row2 < 1 || row2 > 20 || col2 < 1 || col2 > 20) {
		cout << "Было введено некорректное значение\n";
		return -1;
	}
	if (!check(col1, row2)) {
		cout << "Нельзя умножить 1-ю матрицу на 2-ю\n";
		return -1;
	}
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

void fill_matrix_by_hand(int matrix[][cols1], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		cout << "\nВведите элементы " << i + 1 << " строки: ";
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}

}
void multiplic_matrix(int matrix_res[][cols1], int matrix1[][cols1], int matrix2[][cols1], int row1, int col1, int row2, int col2) {
	int row3 = row1;
	int col3 = col2;
	int summa = 0;
	for (int i = 0; i < row3; i++) {
		for (int j = 0; j < col3; j++) {
			summa = 0;
			for (int k = 0; k < col1; k++) {
				summa += matrix1[i][k] * matrix2[k][j];
			}
			matrix_res[i][j] = summa;
		}
	}
}



void fill_matrix_random(int matrix[][cols1], int rows, int cols) {
	srand(0);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = rand() % 100;
		}
	}

}

void print_matrix(int matrix[][cols1], int rows, int cols) {
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