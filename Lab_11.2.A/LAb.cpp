#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <fstream>

using namespace std;

enum Spec { KN, ME, IF, FI, TR };

string specStr[] = { "KN", "ME", "IF", "FI", "TR" };

struct Student
{
    char Prizv[60];
    int Kurs;
    Spec spec;
    double Math;
    double Phisic;
    double Informatics;
};

void Create(string filename);
void Print(string filename);
double ExcellentPercentage(string filename);
void StudentsWithPhysics5(string filename);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename;
    cout << "������ ����� �����: "; cin >> filename;

    int menuItem;
    do {
        cout << endl << endl;
        cout << "������� ��:" << endl << endl;
        cout << " [1] - �������� ����� � ���������" << endl;
        cout << " [2] - ��������� ����� �� �����" << endl;
        cout << " [3] - ������� ��������, �� ������� �� �������" << endl;
        cout << " [4] - ������� ��������, �� �������� � ������ ������ �5�" << endl;
        cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
        cout << "������ ��������: "; cin >> menuItem;
        cout << endl << endl << endl;

        switch (menuItem)
        {
        case 1:
            Create(filename);
            break;
        case 2:
            Print(filename);
            break;
        case 3:
            cout << "������� ��������, �� ������� �� �������: " << ExcellentPercentage(filename) << "%" << endl;
            break;
        case 4:
            StudentsWithPhysics5(filename);
            break;
        case 0:
            break;
        default:
            cout << "�� ����� ��������� ��������! ��� ������ ����� - ����� ��������� ������ ����" << endl;
        }
    } while (menuItem != 0);

    return 0;
}
void Create(string filename)
{
    ofstream f(filename, ios::binary);
    Student s;
    char ch;
    int spec, i = 0;

    do
    {
        i++;
        cin.get();
        cout << "������� �" << i << ":" << endl;
        cout << "�������: "; cin.getline(s.Prizv, 60);
        cout << "����: "; cin >> s.Kurs;
        cout << "������������(0 - KN; 1 - ME; 2 - IF; 3 - FI; 4 - TR): "; cin >> spec;
        s.spec = (Spec)spec;
        cout << "����������: "; cin >> s.Math;
        cout << "Գ����: "; cin >> s.Phisic;
        cout << "�����������: "; cin >> s.Informatics;
        cin.get();

        f.write((char*)&s, sizeof(Student));

        cout << "���������� �������? (Y/N): "; cin >> ch; cout << endl;
    } while (ch == 'Y' || ch == 'y');
    f.close();
    cout << endl;
}

void Print(string filename)
{
    ifstream f(filename, ios::binary);
    Student s;
    int i = 0;

    cout << "==============================================================================" << endl;
    cout << "| � |  �������  | ���� | ������������ | ���������� | Գ���� | ����������� |" << endl;
    cout << "=============================================================================" << endl;

    while (f.read((char*)&s, sizeof(Student)))
    {
        i++;
        cout << "| " << i << " | " << setw(10) << left << s.Prizv << " | " << setw(4) << left << s.Kurs << " | " << setw(13) << left << specStr[s.spec];
        cout << " | " << setw(10) << left << s.Math << " | " << setw(6) << left << s.Phisic << " | " << setw(13) << left << s.Informatics << " | ";
        cout << endl;
        cout << "--------------------------------------------------------------------------" << endl;
    }
    cout << "==============================================================================" << endl;

    f.close();
}

double ExcellentPercentage(string filename)
{
    ifstream f(filename, ios_base::binary);
    Student s;
    int totalStudents = 0, excellentStudents = 0;

    while (f.read((char*)&s, sizeof(Student)))
    {
        totalStudents++;
        if (s.Math == 5 && s.Phisic == 5 && s.Informatics == 5)
            excellentStudents++;
    }
    f.close();

    if (totalStudents == 0)
        return 0.0;

    return 1.0 * excellentStudents / totalStudents * 100;
}

void StudentsWithPhysics5(string filename)
{
    ifstream f(filename, ios_base::binary);
    Student s;

    cout << "������� ��������, �� �������� � ������ ������ \"5\":" << endl;

    while (f.read((char*)&s, sizeof(Student)))
    {
        if (s.Phisic == 5)
            cout << s.Prizv << endl;
    }
    f.close();
}


