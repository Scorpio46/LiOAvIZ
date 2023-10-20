#include <Windows.h> // ��� �����������
#include <iostream> // ��� using namespace std; cout; cin;
#include <cstdlib> // ������� ������������ ������ ������ �����
#include <time.h> // ��� �����������
#include <stdlib.h> // ��� ������� ���������� qsort

using namespace std;
void menu();
void task1();
void Shell();
void QuickSort();
void quicksort(int*, int, int);
void QuickSort2();
int comp(const void*, const void*);
int n;

void main() {

	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "              ������� ������� ����� ������������ ���������!!!" << endl
		<< "��� ��������� ������������� ��� ���������� ���������� ���������� ���������" << endl
		<< "��������  ����������  �������  �  �����������  ��  ������������  ��  �����," << endl
		<< "� ����� ��� ��������� �������������� ���������� ����� � ������� ����������." << endl;
	system("pause");
	system("cls");

	menu();

	while (n != 0) {
		switch (n) {
		case 1:
			task1();

			system("pause");
			system("cls");
			menu();
			break;
		case 2:
			Shell();

			system("pause");
			system("cls");
			menu();
			break;
		case 3:
			QuickSort();

			system("pause");
			system("cls");
			menu();
			break;
		case 4:
			QuickSort();

			system("pause");
			system("cls");
			menu();
			break;
		default:
			cout << "����������� ������ ����� ����!" << endl;

			system("pause");
			system("cls");
			menu();
			break;
		}
	}
}
void menu() {
	cout << "�������� ����� ����:" << endl
		<< "(1) ������� �������;" << endl
		<< "(2) ���������� �����;" << endl
		<< "(3) ������� ����������;" << endl
		<< "(4) ������� ���������� 2;" << endl
		<< "(0) ����� �� ���������." << endl
		<< "��� �����: ";
	cin >> n;
	system("cls");
}
void task1() {
	int a, max = 100, min = 0;
	cout << "���������� ������� n-�� �������." << endl
		<< "n = ";
	cin >> a;

	int **matrix0, **matrix1, **matrix2; // ������� ��� ���!!!
	matrix0 = new int *[a]; // ������ ����������� �����������
	matrix1 = new int *[a]; // ������ ������� = ���-�� �����
	matrix2 = new int *[a];
	for (int i = 0; i < a; i++) {
		matrix0[i] = new int[a]; // ������� ������� � ������
		matrix1[i] = new int[a]; // ������ ������� = ���-�� ��������
		matrix2[i] = new int[a];
	}
	clock_t start, end;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			matrix1[i][j] = min + rand() % (max - min + 1);
			matrix2[i][j] = min + rand() % (max - min + 1);
		}
	}
	start = clock();
	for (int i = 0, c = 0; i < a; i++) {
		for (int j = 0; j < a; j++, c++) {
			matrix0[i][j] = 0;
			for (int b = 0; b < a; b++) {
				matrix0[i][j] += matrix1[i][b] * matrix2[b][j];
			}
			cout << "[" << i +1 << "]" << "[" << j + 1 << "]: "
				<< "[" << matrix0[i][j] << "]\t";
			if (c % 3 == 2) {
				cout << endl;
			}
		}
	}
	end = clock();
	cout << endl << "��������� ��������� ������� ������� [" << a << "]["
		<< a << "] �� " << (end - start) /*/ CLK_TCK*/ << " ������." << endl;
	free(matrix0);
	free(matrix1);
	free(matrix2);
}
void Shell() {
	int count, e, max = 100, min = 0;
	cout << "������� ������ �������: ";
	cin >> count;

	int *items = new int[count];
	clock_t start, end;

	cout << "������� ��� ��������� ������:" << endl
		<< "(1) ���������� ����������;" << endl
		<< "(2) ������������� ����������;" << endl
		<< "(3) ���������� ����������;" << endl
		<< "(4) �������� �������������, �������� ������������." << endl
		<< "��� �����: ";
	cin >> e;

	switch (e) {
	case 1:
		for (int i = 0; i < count; i++) {
			items[i] = min + rand() % (max - min + 1);
		}
		break;
	case 2:
		for (int i = 0; i < count; i++) {
			items[i] = i + 1;
		}
		break;
	case 3:
		for (int i = 0; i < count; i++) {
			items[i] = count - i;
		}
		break;
	case 4:
		for (int i = 0, j = count / 2; i < count; i++) {
			if (i < j) {
				items[i] = i;
			}
			if (i >= j) {
				items[i] = count - i;
			}
		}
		break;
	}
	for (int i = 0; i < count; i++) {
		cout << "[" << i + 1 << "]" << ": [" << items[i] << "]\t";
		if (i % 5 == 4) {
			cout << endl;
		}
	}
	start = clock();
	for (int i = 5; i > 0; i--) { // ������, ���������� �������������
		for (int j = 0; j < i; j++) { // ��� � ���� �����
			for (int b = i + j; b < count; b += i) { // ���������� �����
				for (int c = b - i; c >= 0 and items[c] > items[c + i]; c -= i) { // ��������� �����
					swap(items[c], items[c + i]); // ������ ������� ���� �����
				}
			}
		}
	}
	cout << endl;
	for (int i = 0; i < count; i++) {
		cout << "[" << i + 1 << "]" << ": [" << items[i] << "]\t";
		if (i % 5 == 4) {
			cout << endl;
		}
	}
	cout << endl;
	end = clock();
	cout << "��������� ��������� ���������� �� ������ ����� �� "
		<< (end - start) /*/ CLK_TCK*/ << " ������." << endl;
	free(items);
}
void QuickSort() {
	int count, e, max = 100, min = 0;
	cout << "������� ������ �������: ";
	cin >> count;

	int* items = new int[count];
	clock_t start, end;

	cout << "������� ��� ��������� ������:" << endl
		<< "(1) ���������� ����������;" << endl
		<< "(2) ������������� ����������;" << endl
		<< "(3) ���������� ����������;" << endl
		<< "(4) �������� �������������, �������� ������������." << endl
		<< "��� �����: ";
	cin >> e;

	switch (e) {
	case 1:
		for (int i = 0; i < count; i++) {
			items[i] = min + rand() % (max - min + 1);
		}
		break;
	case 2:
		for (int i = 0; i < count; i++) {
			items[i] = i + 1;
		}
		break;
	case 3:
		for (int i = 0; i < count; i++) {
			items[i] = count - i;
		}
		break;
	case 4:
		for (int i = 0, j = count / 2; i < count; i++) {
			if (i < j) {
				items[i] = i;
			}
			if (i >= j) {
				items[i] = count - i;
			}
		}
		break;
	}
	for (int i = 0; i < count; i++) {
		cout << "[" << i + 1 << "]" << ": [" << items[i] << "]\t";
		if (i % 5 == 4) {
			cout << endl;
		}
	}
	start = clock();
	///////////////////////////////////////////////////////////////
	int left, right;
	left = 0;
	right = count - 1;
	quicksort(items, left, right);
	///////////////////////////////////////////////////////////////
	cout << endl;
	for (int i = 0; i < count; i++) {
		cout << "[" << i + 1 << "]" << ": [" << items[i] << "]\t";
		if (i % 5 == 4) {
			cout << endl;
		}
	}
	cout << endl;
	end = clock();
	cout << "��������� ��������� ���������� �� ������ ����� �� "
		<< (end - start) /*/ CLK_TCK*/ << " ������." << endl;
	free(items);
}
void quicksort(int* items, int left, int right) {
	int i = left;
	int j = right;
	int tmp;
	int pivot = items[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (items[i] < pivot)
			i++;
		while (items[j] > pivot)
			j--;
		if (i <= j) {
			tmp = items[i];
			items[i] = items[j];
			items[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quicksort(items, left, j);
	if (i < right)
		quicksort(items, i, right);
}
void QuickSort2() {
	int count, e, max = 100, min = 0;
	cout << "������� ������ �������: ";
	cin >> count;

	int* items = new int[count];
	clock_t start, end;

	cout << "������� ��� ��������� ������:" << endl
		<< "(1) ���������� ����������;" << endl
		<< "(2) ������������� ����������;" << endl
		<< "(3) ���������� ����������;" << endl
		<< "(4) �������� �������������, �������� ������������." << endl
		<< "��� �����: ";
	cin >> e;

	switch (e) {
	case 1:
		for (int i = 0; i < count; i++) {
			items[i] = min + rand() % (max - min + 1);
		}
		break;
	case 2:
		for (int i = 0; i < count; i++) {
			items[i] = i + 1;
		}
		break;
	case 3:
		for (int i = 0; i < count; i++) {
			items[i] = count - i;
		}
		break;
	case 4:
		for (int i = 0, j = count / 2; i < count; i++) {
			if (i < j) {
				items[i] = i;
			}
			if (i >= j) {
				items[i] = count - i;
			}
		}
		break;
	}
	for (int i = 0; i < count; i++) {
		cout << "[" << i + 1 << "]" << ": [" << items[i] << "]\t";
		if (i % 5 == 4) {
			cout << endl;
		}
	}
	start = clock();
	///////////////////////////////////////////////////////////////
	int n;
	qsort(items, count, sizeof(int), comp);
	for (n = 0; n < count; n++)
		printf("%d ", items[n]);
	///////////////////////////////////////////////////////////////
	cout << endl;
	for (int i = 0; i < count; i++) {
		cout << "[" << i + 1 << "]" << ": [" << items[i] << "]\t";
		if (i % 5 == 4) {
			cout << endl;
		}
	}
	cout << endl;
	end = clock();
	cout << "��������� ��������� ���������� �� ������ ����� �� "
		<< (end - start) /*/ CLK_TCK*/ << " ������." << endl;
	free(items);
}
int comp(const void* i, const void* j) {
	return *(int*)i - *(int*)j;
}