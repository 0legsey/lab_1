// lab_1.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#define SIZE 2000
#include <iostream>
#include <Vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<char> create_array();

vector<char> arr = create_array();
int flag = 0;

void simple_sort(vector<char>* arr) {
    for (int i = 0; i < arr->size(); i++) {
        int k = i;
        char x = arr->at(i);
        for (int j = i + 1; j < arr->size(); j++) {
            if ((int)arr->at(j) < x) {
                k = j;
                x = arr->at(j);
            }
        }
        arr->at(k) = arr->at(i);
        arr->at(i) = x;
    }
}

void quick_sort(vector<char>* arr, int left, int right) {
    int i = left;
    int j = right;
    char middle = arr->at((i + j + 1) / 2);
    do {
        while (arr->at(i) < middle) i++;
        while (arr->at(j) > middle) j--;
        if (i <= j) {
            swap(arr->at(i), arr->at(j));
            i++; j--;
        }
    } while (i <= j);
    if (left < j)
        quick_sort(arr, left, j);
    if (i < right)
        quick_sort(arr, i, right);
}

bool binary_search(vector<char>* arr, int left, int right, char key) {
    bool flag = 0;
    int middle;
    while ((left <= right) && (flag != 1)) {
        middle = (left + right) / 2;
        if ((int)arr->at(middle) == (int)key)
            flag = 1;
        if ((int)arr->at(middle) > (int)key)
            right = middle - 1;
        else left = middle + 1;
    }
    return flag;
}

vector<char> create_array() {
    vector<char> arr;
    char c = NULL;
    for (int i = 0; i < SIZE; i++) {
        do {
            c = rand();
        } while ((int)c <= 32);
        arr.push_back(fabs(c));
    }
    for (int i = 0; i < SIZE; i++)
        cout << arr.at(i) << " ";
    cout << endl;
    return arr;
}

int menu() {
    int answer, answer_sort;
    cout << endl;
    cout << "�������� ����� ������ ���������:\n1) ����������\n2) �������� �����\n3) ����� �� ���������\n";
    do {
        cout << "�����:\n";
        cin >> answer;
    } while (answer < 1 || answer > 3);
    switch (answer) {
    case 1: {
        cout << "�������� ������ ����������:\n1) ������� ����������\n2) ���������� ����������\n";
        do {
            cout << "�����:\n";
            cin >> answer_sort;
        } while (answer_sort < 1 || answer_sort > 2);
        switch (answer_sort) {
        case 1: {
            auto start = high_resolution_clock::now();
            simple_sort(&arr);
            auto end = high_resolution_clock::now();
            cout << "����� ���������� " << SIZE << " ���������: ";
            cout << duration_cast<microseconds>(end - start).count() << " �����������(�\\�)" << endl;
            for (int i = 0; i < arr.size(); i++)
                cout << arr.at(i) << " ";
            cout << endl;
            break;
        }
        case 2: {
            auto start = high_resolution_clock::now();
            quick_sort(&arr, 0, arr.size() - 1);
            auto end = high_resolution_clock::now();
            cout << "����� ���������� " << SIZE << " ���������: ";
            cout << duration_cast<microseconds>(end - start).count() << " �����������(�\\�)" << endl;
            for (int i = 0; i < arr.size(); i++)
                cout << arr.at(i) << " ";
            cout << endl;
            break;
        }
        }
        flag = 1;
        break;
    }
    case 2: {
        if (flag) {
            auto start = high_resolution_clock::now();
            bool flag = binary_search(&arr, 0, arr.size() - 1, '}');
            auto end = high_resolution_clock::now();
            cout << "����� ��������� ������ � ������� �� " << SIZE << " ���������: ";
            cout << duration_cast<nanoseconds>(end - start).count() << " ����������(�\\�)" << endl;
            cout << endl;
            if (flag)
                cout << "������� ���� � �������";
            else
                cout << "�������� ��� � �������";
            cout << endl;
        }
        else {
            cout << "������ �� ������������";
        }
        break;
    }
    case 3: {
        return 0;
        break;
    }
    }
    menu();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    menu();
}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.
