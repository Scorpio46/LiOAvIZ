#include "tree.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Tree* t = new Tree;
    int var;

    t->left = NULL;
    t->right = NULL;

    cout << "������� ������ (����� �����):" << endl;
    cin >> t->data;

    do {
        cout << "�������� ��������:\n0 - �����             1 - �������� ����\n2 - ������� ������    3 - ����� �������" << endl
            << "4 - ������ ��� ����������           5 - ������ ����������� ���������" << endl;
        cin >> var;

        switch (var)
        {
        case 0:
            goto L1;
        case 1:
            cout << "������� ������� (����� �����):" << endl;
            cin >> var;
            AddSheet(t, var);
            break;
        case 2:
            PrintTree(t);
            break;
        case 3:
            cout << "������� ������� ����� �����:" << endl;
            cin >> var;
            search(t, var);
            break;
        case 4:
            cout << "������� ������� (����� �����):" << endl;
            cin >> var;
            wr_block(t, var);
            break;
        }
    } while (1);
L1:
    return 0;
}