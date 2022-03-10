#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif



#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>

using namespace std;

int translate_to_10(char* str);

int find_numbers(char* s1, char* raz, int* mas, int& j);

int main() {
	setlocale(LC_ALL, "Russian");
	char s[256];
	int mas[256];
	char raz[] = " ,";
	int j = 0;
	cout << "Введите предложение не больше(256 символов):\n";
	cin.getline(s, 256, '\n');
	char* s1 = strtok(s, raz);
	j = find_numbers(s1, raz, mas, j);
	cout << "Числа, найденные в тексте и переведнные в 10-ую сс: ";
	for (int i = 0; i < j; i++) {
		cout << mas[i] << " ";
	}


}


int translate_to_10(char* str) {
	int number_10 = 0;
	for (int i = 1; i < strlen(str); i++) {
		number_10 += (str[i] - '0') * pow(8, strlen(str) - 1 - i);
	}
	return number_10;
}


int find_numbers(char* s1, char* raz, int* mas, int& j) {
	while (s1 != NULL) {
		if (s1[0] == '$') {
			mas[j] = translate_to_10(s1);
			j++;
		}
		s1 = strtok(NULL, raz);
	}
	return j;
}