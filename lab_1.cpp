// lab_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
    cout << "Выберите режим работы программы:\n1) Сортировка\n2) Бинарный поиск\n3) Выход из программы\n";
    do {
        cout << "Ответ:\n";
        cin >> answer;
    } while (answer < 1 || answer > 3);
    switch (answer) {
    case 1: {
        cout << "Выберите способ сортировки:\n1) Простая сортировка\n2) Улучшенная сортировка\n";
        do {
            cout << "Ответ:\n";
            cin >> answer_sort;
        } while (answer_sort < 1 || answer_sort > 2);
        switch (answer_sort) {
        case 1: {
            auto start = high_resolution_clock::now();
            simple_sort(&arr);
            auto end = high_resolution_clock::now();
            cout << "Время сортировки " << SIZE << " элементов: ";
            cout << duration_cast<microseconds>(end - start).count() << " микросекунд(а\\ы)" << endl;
            for (int i = 0; i < arr.size(); i++)
                cout << arr.at(i) << " ";
            cout << endl;
            break;
        }
        case 2: {
            auto start = high_resolution_clock::now();
            quick_sort(&arr, 0, arr.size() - 1);
            auto end = high_resolution_clock::now();
            cout << "Время сортировки " << SIZE << " элементов: ";
            cout << duration_cast<microseconds>(end - start).count() << " микросекунд(а\\ы)" << endl;
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
            cout << "Время бинарного поиска в массиве из " << SIZE << " элементов: ";
            cout << duration_cast<nanoseconds>(end - start).count() << " наносекунд(а\\ы)" << endl;
            cout << endl;
            if (flag)
                cout << "Элемент есть в массиве";
            else
                cout << "Элемента нет в массиве";
            cout << endl;
        }
        else {
            cout << "Массив не отсортирован";
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
