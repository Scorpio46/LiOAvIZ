#include "spiski.h"

template <typename T>
void menu(T str);

int main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice, value, prioriti;
    cout << "�������� ���������:\n1-����\n2-�������\n3-������������ �������" << endl;
    cin >> choice;

    if (choice == 1)
    {
        Stack st;
        while (1)
        {
            system("cls");
            cout << "�������� ��������\n0-�����\n1-����������\n2-��������\n3-������" << endl;
            cin >> choice;

            if (choice == 1) st.print();
            else if (choice == 2)
            {
                cout << "������� �����" << endl;
                cin >> value;
                st.add(value);
            }
            else if (choice == 3) st.pop();
            else if (choice == 0) break;
            else cout << "�������� �����!" << endl;
        }
    }
    else if (choice == 2)
    {
        Queue qe;
        while (1)
        {
            system("cls");
            cout << "�������� ��������\n0-�����\n1-����������\n2-��������\n3-������" << endl;
            cin >> choice;

            if (choice == 1) qe.print();
            else if (choice == 2)
            {
                cout << "������� �����" << endl;
                cin >> value;
                qe.add(value);
            }
            else if (choice == 3) qe.pop();
            else if (choice == 0) break;
            else cout << "�������� �����!" << endl;
        }
    }
    else if (choice == 3)
    {
        PQueue qe;
        while (1)
        {
            system("cls");
            cout << "�������� ��������\n0-�����\n1-����������\n2-��������\n3-������" << endl;
            cin >> choice;

            if (choice == 1) qe.print();
            else if (choice == 2)
            {
                cout << "������� �����" << endl;
                cin >> value;
                cout << "������� ���������" << endl;
                cin >> prioriti;
                qe.add(value, prioriti);
            }
            else if (choice == 3) qe.pop();
            else if (choice == 0) break;
            else cout << "�������� �����!" << endl;
        }
    }
    else cout << "�������� �����!" << endl;
    return 0;
}

template <typename T>
void menu(T str)
{
    ;
}
