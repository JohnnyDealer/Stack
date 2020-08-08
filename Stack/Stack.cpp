// Stack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
#include <stack>
#include "MyStack.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    MyStack myStack;
    string choice = "";
    bool flag = true;
    cout << "Команды: pop / push a (где a - число) / rand a (где a - число) / top / show / clear / sort / size / exit" << endl;
    while (flag) {
        cin >> choice;
        if (choice == "pop")        
            myStack.Pop();        
        if (choice == "push")
        {
            int a = 0;
            cin >> a;
            myStack.Push(a);
        }            
        if (choice == "top")
            myStack.Top();
        if (choice == "size")
            myStack.Size();
        if (choice == "empty")
            myStack.Empty();
        if (choice == "show")
            myStack.ShowAllElements();
        if (choice == "sort")
            myStack.Sort();
        if (choice == "sort opt")
            myStack.Sort_Optimized();
        if (choice == "exit")
            flag = false;
        if (choice == "clear")
            myStack.Clear();
        if (choice == "rand")
        {
            int a = 0;
            cin >> a;
            myStack.Randomize(a);
        }            
    }
    return 0;
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
