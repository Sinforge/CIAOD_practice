#include <iostream>
#include <string>
using namespace std;

int translate_to_10(string str);

int find_numbers(string s, string raz, int* mas, int& j);

int main() {
	setlocale(LC_ALL, "Russian");
	string s, raz = " ,";
	int j = 0;
	int mas[256];
	cout << "Введите предложение:\n";
	getline(cin, s);
	j = find_numbers(s, raz, mas, j);
	cout << "Числа, найденные в тексте и переведнные в 10-ую сс: ";
	for (int i = 0; i < j; i++) {
		cout << mas[i] << " ";
	}
}


int translate_to_10(string str) {
	int number_10 = 0;
	for (int i = 1; i < str.size(); i++) {
		number_10 += (str[i] - '0') * pow(8, str.size() - 1 - i);
	}
	return number_10;
}

int find_numbers(string s, string raz, int* mas, int& j)
{
	size_t start_index = 0, end_index;
	while (start_index != string::npos) {
		end_index = s.find_first_of(raz, start_index);
		if (s[start_index] == '$') {
			mas[j] = translate_to_10(s.substr(start_index, (end_index - start_index)));
			j++;
		}
		start_index = s.find_first_not_of(raz, end_index);
	}
	return j;
}
