
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct coord {
	int x = INT_MIN;
	int y = INT_MIN;
};

struct result {
	coord pt1;
	coord pt2;
	coord pt3;
	double S = INT_MIN;
};

struct triangle {
	coord side1;
	coord side2;
	coord side3;
};
double vector_lenght(coord pt);

coord coord_minus(coord pt1, coord pt2);

triangle triangle_sides(coord pt1, coord pt2, coord pt3);

void fill_set_by_hand(vector<coord>& vector, int size);

result find_perfect_triangle(vector<coord> set1, vector<coord> set2);

void print_result(result res);

bool check_in_triangle(coord pt1, coord pt2, coord pt3, vector<coord> set);

double square(coord pt1, coord pt2, coord pt3);


int main() {
	setlocale(LC_ALL, "");
	int menu;
	int size1, size2;
	result result1;
	vector<coord> vector1;
	vector<coord> vector2;
	cout << "Введите количество точек в первом множестве(Не меньше 3)\n";
	cin >> size1;
	cout << "Введите количество точек во втором множестве\n";
	cin >> size2;
	if (size1 < 3 || size2 < 0) {
		cout << "Было введено некорректное значение\n";
		return -1;
	}
	cout << "Пользовательское меню:\n0- Для выхода\n1-Заполнить первое множество точек\n2-Заполнить второе множество точек\n3-Выполнить задание\n4-Вывести результат выполнения 1\n";
	cin >> menu;


	while (menu) {


		switch (menu) {
		case 1:
			fill_set_by_hand(vector1, size1);
			break;

		case 2:
			fill_set_by_hand(vector2, size2);
			break;
		case 3:
			result1 = find_perfect_triangle(vector1, vector2);
			break;
		case 4:
			print_result(result1);
			break;
		}
		cout << "\nПользовательское меню:\n0- Для выхода\n1-Заполнить первое множество точек\n2-Заполнить второе множество точек\n3-Выполнить задание\n4-Вывести результат выполнения 1\n";
		cin >> menu;

	}
}
void fill_set_by_hand(vector<coord>& vector, int size) {
	vector.resize(size);
	for (int i = 0; i < size; i++) {
		cout << "\nВведите координаты точки на плоскости(x y):";
		cin >> vector[i].x;
		cin >> vector[i].y;
	}


}

result find_perfect_triangle(vector<coord> set1, vector<coord> set2) {
	double S = INT_MAX;
	result result;
	for (int i = 0; i < set1.size() - 2; i++) {
		for (int j = i + 1; j < set1.size() - 1; j++) {
			for (int k = j + 1; k < set1.size(); k++) {
				if (check_in_triangle(set1[i], set1[j], set1[k], set2) && (S > square(set1[i], set1[j], set1[k]))) {
					S = square(set1[i], set1[j], set1[k]);
					result.pt1 = set1[i];
					result.pt2 = set1[j];
					result.pt3 = set1[k];
					result.S = S;

				}

			}
		}
	}
	return result;
}

void print_result(result res) {
	cout << "Треугольник: \n";
	cout << "\tТочка 1 : (" << res.pt1.x << " " << res.pt1.y << ")\n";
	cout << "\tТочка 2 : (" << res.pt2.x << " " << res.pt2.y << ")\n";
	cout << "\tТочка 3 : (" << res.pt3.x << " " << res.pt3.y << ")\n";
	cout << "\tS = " << res.S << endl;

}

bool check_in_triangle(coord pt1, coord pt2, coord pt3, vector<coord> set) {
	bool flag = true;
	coord v1, v2, v3;
	triangle tr = triangle_sides(pt1, pt2, pt3);
	int ch1, ch2, ch3;
	for (int i = 0; i < set.size(); i++) {
		v1 = coord_minus(set[i], pt1);
		v2 = coord_minus(set[i], pt2);
		v3 = coord_minus(set[i], pt3);
		ch1 = tr.side1.x * v1.y - v1.x * tr.side1.y;
		ch2 = tr.side2.x * v2.y - v2.x * tr.side2.y;
		ch3 = tr.side3.x * v3.y - v3.x * tr.side3.y;
		if ((ch1 >= 0 && ch2 >= 0 && ch3 >= 0) || (ch1 <= 0 && ch2 <= 0 && ch3 <= 0)) {
			continue;
		}
		else {
			flag = false;
			break;

		}
	}
	return flag;
}



double square(coord pt1, coord pt2, coord pt3) {
	triangle tr = triangle_sides(pt1, pt2, pt3);
	double a = vector_lenght(tr.side1);
	double b = vector_lenght(tr.side2);
	double c = vector_lenght(tr.side3);
	double p = (a + b + c) / 2;

	return sqrt(p * (p - a) * (p - b) * (p - c));
}



double vector_lenght(coord pt) {
	return sqrt(pow(pt.x, 2) + pow(pt.y, 2));
}

coord coord_minus(coord pt1, coord pt2) {
	coord pt_res;
	pt_res.x = pt1.x - pt2.x;
	pt_res.y = pt1.y - pt2.y;
	return pt_res;
}
triangle triangle_sides(coord pt1, coord pt2, coord pt3) {
	triangle tr;
	tr.side1 = coord_minus(pt2, pt1);
	tr.side2 = coord_minus(pt3, pt2);
	tr.side3 = coord_minus(pt1, pt3);
	return tr;
}