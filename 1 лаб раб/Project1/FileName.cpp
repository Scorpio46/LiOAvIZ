#include <Windows.h>
#include <iostream>
#include <string.h>
#include <locale.h>
#include <time.h>

using namespace std;

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	// Задание 1-3

	float n;

	cout << "Босс, массив какого размера тебе нужен?" << endl
		<< "Не тупи,ты можешь взять любое положительное число: ";
	cin >> n;

	if (n <= 0) {
		cout << "Пооонятно. Мне с тобой разговаривать дальше не о чем >:(";
		return;
	}
	if (ceil(n) != n) {
		cout << "Ух. И надо было тебе взять вещественное?" << endl;
	}

	int *numbers{ new int[n] }; // int *numbers = new int[n]; // Задание 3
	int max, min, max1, min1;

	cout << "Сейчас я заполню массив случайными ЦЕЛЫМИ числами. Есть пожелания?" << endl
		<< "От: ";
	cin >> min;
	cout << "До: ";
	cin >> max;

	if (max < min) {
		max1 = max;
		min1 = min;
		max = min1;
		min = max1;
	}
	else {
		max1 = min;
		min1 = max;
	}
	cout << "Вот содержимое твоего массива: ";

	for (int i = 0, j = 1; i < n; i++) {
		numbers[i] = min + rand() % (max - min + 1);

		cout << j++ << "=" << numbers[i] << "; ";
		
		if (max1 < numbers[i]) {
			max1 = numbers[i];
		}
		if (min1 > numbers[i]) {
			min1 = numbers[i];
		}
		if (i % 8 == 3) {
			cout << endl;
		}
	}
	cout << "макс=" << max1 << "; мин=" << min1 << "." << endl
		<< "Разница между макс. и мин. значениями " << max1 - min1 << "."; // Задание 1
	if (ceil(n) != n) {
		cout << "\nА ты чего ожидал когда брал вещественное число?" << endl
			<< "Явно же округления в большую сторону ;)";
	}
	// Задание 4

	cout << "\n\n" << "Босс, я дам тебе матрицу 3 на 5 заполненную числами от -10 до 10." << endl
		<< "И НЕТ, я не собираюсь делать дЕМОНический двумерный массив!!!";

	int matrix[3][5];

	for (int i = 0; i < 3; i++) {
		cout << endl;
		for (int j = 0; j < 5; j++) {
			matrix[i][j] = rand() % 21 - 10;
			cout << "[" << matrix[i][j] << "]\t";
		}
	}
	int a;

	cout << "\nБудем искать сумму каждого столбца(0) или каждой строки(1)?" << endl
		<< "Жду ответа: ";
	cin >> a;

	switch (a) {
	case 0:
		for (int i = 0, b = 0, c = 1; i < 5; i++, c++) {
			for (int j = 0; j < 3; j++) {
				b = matrix[j][i] + b;
			}
			cout << "Сумма " << c << " столбца равна " << b << "." << endl;
			b = 0;
		}
		break;
	case 1:
		for (int i = 0, b = 0, c = 1; i < 3; i++, c++) {
			for (int j = 0; j < 5; j++) {
				b = matrix[i][j] + b;
			}
			cout << "Сумма " << c << " строки равна " << b << "." << endl;
			b = 0;
		}
		break;
	default:
		cout << "Босс, ты чего? По кнопке промазал? Я не попугай, повторять не буду >:(" << endl;
		break;
	}
	// Задание 5

	cout << "\nБосс, а теперь давай заполним список." << endl;
	
	struct student {
		int Nomzach;
		char famil[20], name[20], facult[20];
	} stud[3];

	for (int i = 0; i < 3; i++) {
		cout << "Введи фамилию " << i + 1 << " студента: ";
		cin >> stud[i].famil;
		cout << "Введи имя " << i + 1 << " студента: ";
		cin >> stud[i].name;
		cout << "Введи факультет " << i + 1 << " студента: ";
		cin >> stud[i].facult;
		cout << "Введи номер зачётной книжки " << i + 1 << " студента: ";
		cin >> stud[i].Nomzach;
	}
	cout << endl;

	for (int i = 0; i < 3; i++) {
		cout << i + 1 << " студент: " << stud[i].famil << " " << stud[i].name << endl
			<< "Обучается на факультете: " << stud[i].facult << endl
			<< "Номер зачётной книжки: " << stud[i].Nomzach << endl;
	}
	int s;

	cout << "\nБосс, как будем осуществлять поиск? Давай начнём с того что тебе известно :3" << endl
		<< "Фамилия(0), имя(1), факультет(2) или номер зачётной книжки(3): ";
	cin >> s;

	char x[20];
	int d;

	switch (s) {
	case 0:
		cout << "Введи фамилию студента: ";
		cin >> x;
		for (int i = 0; i < 3; i++) {
			if (strcmp(stud[i].famil, x) == 0) {
				cout << i + 1 << " студент: " << stud[i].famil << " " << stud[i].name << endl
					<< "Обучается на факультете: " << stud[i].facult << endl
					<< "Номер зачётной книжки: " << stud[i].Nomzach << endl;
			}
		}
		break;
	case 1:
		cout << "Введи имя студента: ";
		cin >> x;
		for (int i = 0; i < 3; i++) {
			if (strcmp(stud[i].name, x) == 0) {
				cout << i + 1 << " студент: " << stud[i].famil << " " << stud[i].name << endl
					<< "Обучается на факультете: " << stud[i].facult << endl
					<< "Номер зачётной книжки: " << stud[i].Nomzach << endl;
			}
		}
		break;
	case 2:
		cout << "Введи факультет студента: ";
		cin >> x;
		for (int i = 0; i < 3; i++) {
			if (strcmp(stud[i].facult, x) == 0) {
				cout << i + 1 << " студент: " << stud[i].famil << " " << stud[i].name << endl
					<< "Обучается на факультете: " << stud[i].facult << endl
					<< "Номер зачётной книжки: " << stud[i].Nomzach << endl;
			}
		}
		break;
	case 3:
		cout << "Введи номер зачётной книжки студента: ";
		cin >> d;
		for (int i = 0; i < 3; i++) {
			if (d == stud[i].Nomzach) {
				cout << i + 1 << " студент: " << stud[i].famil << " " << stud[i].name << endl
					<< "Обучается на факультете: " << stud[i].facult << endl
					<< "Номер зачётной книжки: " << stud[i].Nomzach << endl;
			}
		}
		break;
	default:
		cout << "Босс, ты чего? По кнопке промазал? Я не попугай, повторять не буду >:(" << endl;
		break;
	}
	delete[] numbers;
}