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

	// ������� 1-3

	float n;

	cout << "����, ������ ������ ������� ���� �����?" << endl
		<< "�� ����,�� ������ ����� ����� ������������� �����: ";
	cin >> n;

	if (n <= 0) {
		cout << "���������. ��� � ����� ������������� ������ �� � ��� >:(";
		return;
	}
	if (ceil(n) != n) {
		cout << "��. � ���� ���� ���� ����� ������������?" << endl;
	}

	int *numbers{ new int[n] }; // int *numbers = new int[n]; // ������� 3
	int max, min, max1, min1;

	cout << "������ � ������� ������ ���������� ������ �������. ���� ���������?" << endl
		<< "��: ";
	cin >> min;
	cout << "��: ";
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
	cout << "��� ���������� ������ �������: ";

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
	cout << "����=" << max1 << "; ���=" << min1 << "." << endl
		<< "������� ����� ����. � ���. ���������� " << max1 - min1 << "."; // ������� 1
	if (ceil(n) != n) {
		cout << "\n� �� ���� ������ ����� ���� ������������ �����?" << endl
			<< "���� �� ���������� � ������� ������� ;)";
	}
	// ������� 4

	cout << "\n\n" << "����, � ��� ���� ������� 3 �� 5 ����������� ������� �� -10 �� 10." << endl
		<< "� ���, � �� ��������� ������ ������������ ��������� ������!!!";

	int matrix[3][5];

	for (int i = 0; i < 3; i++) {
		cout << endl;
		for (int j = 0; j < 5; j++) {
			matrix[i][j] = rand() % 21 - 10;
			cout << "[" << matrix[i][j] << "]\t";
		}
	}
	int a;

	cout << "\n����� ������ ����� ������� �������(0) ��� ������ ������(1)?" << endl
		<< "��� ������: ";
	cin >> a;

	switch (a) {
	case 0:
		for (int i = 0, b = 0, c = 1; i < 5; i++, c++) {
			for (int j = 0; j < 3; j++) {
				b = matrix[j][i] + b;
			}
			cout << "����� " << c << " ������� ����� " << b << "." << endl;
			b = 0;
		}
		break;
	case 1:
		for (int i = 0, b = 0, c = 1; i < 3; i++, c++) {
			for (int j = 0; j < 5; j++) {
				b = matrix[i][j] + b;
			}
			cout << "����� " << c << " ������ ����� " << b << "." << endl;
			b = 0;
		}
		break;
	default:
		cout << "����, �� ����? �� ������ ��������? � �� �������, ��������� �� ���� >:(" << endl;
		break;
	}
	// ������� 5

	cout << "\n����, � ������ ����� �������� ������." << endl;
	
	struct student {
		int Nomzach;
		char famil[20], name[20], facult[20];
	} stud[3];

	for (int i = 0; i < 3; i++) {
		cout << "����� ������� " << i + 1 << " ��������: ";
		cin >> stud[i].famil;
		cout << "����� ��� " << i + 1 << " ��������: ";
		cin >> stud[i].name;
		cout << "����� ��������� " << i + 1 << " ��������: ";
		cin >> stud[i].facult;
		cout << "����� ����� �������� ������ " << i + 1 << " ��������: ";
		cin >> stud[i].Nomzach;
	}
	cout << endl;

	for (int i = 0; i < 3; i++) {
		cout << i + 1 << " �������: " << stud[i].famil << " " << stud[i].name << endl
			<< "��������� �� ����������: " << stud[i].facult << endl
			<< "����� �������� ������: " << stud[i].Nomzach << endl;
	}
	int s;

	cout << "\n����, ��� ����� ������������ �����? ����� ����� � ���� ��� ���� �������� :3" << endl
		<< "�������(0), ���(1), ���������(2) ��� ����� �������� ������(3): ";
	cin >> s;

	char x[20];
	int d;

	switch (s) {
	case 0:
		cout << "����� ������� ��������: ";
		cin >> x;
		for (int i = 0; i < 3; i++) {
			if (strcmp(stud[i].famil, x) == 0) {
				cout << i + 1 << " �������: " << stud[i].famil << " " << stud[i].name << endl
					<< "��������� �� ����������: " << stud[i].facult << endl
					<< "����� �������� ������: " << stud[i].Nomzach << endl;
			}
		}
		break;
	case 1:
		cout << "����� ��� ��������: ";
		cin >> x;
		for (int i = 0; i < 3; i++) {
			if (strcmp(stud[i].name, x) == 0) {
				cout << i + 1 << " �������: " << stud[i].famil << " " << stud[i].name << endl
					<< "��������� �� ����������: " << stud[i].facult << endl
					<< "����� �������� ������: " << stud[i].Nomzach << endl;
			}
		}
		break;
	case 2:
		cout << "����� ��������� ��������: ";
		cin >> x;
		for (int i = 0; i < 3; i++) {
			if (strcmp(stud[i].facult, x) == 0) {
				cout << i + 1 << " �������: " << stud[i].famil << " " << stud[i].name << endl
					<< "��������� �� ����������: " << stud[i].facult << endl
					<< "����� �������� ������: " << stud[i].Nomzach << endl;
			}
		}
		break;
	case 3:
		cout << "����� ����� �������� ������ ��������: ";
		cin >> d;
		for (int i = 0; i < 3; i++) {
			if (d == stud[i].Nomzach) {
				cout << i + 1 << " �������: " << stud[i].famil << " " << stud[i].name << endl
					<< "��������� �� ����������: " << stud[i].facult << endl
					<< "����� �������� ������: " << stud[i].Nomzach << endl;
			}
		}
		break;
	default:
		cout << "����, �� ����? �� ������ ��������? � �� �������, ��������� �� ���� >:(" << endl;
		break;
	}
	delete[] numbers;
}