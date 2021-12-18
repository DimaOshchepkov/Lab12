// Lab12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "fail.h"

int main()
{
    enum TASK {OUT_ARR = 1, OVERWRITING, NUMBER3, BREAKETS, VOCABLUARY, ISENTRY_WORD, BIN};
    int z;
    const char* const task[] = { "outArr", "overWriting", "number3","breakets", "vocabluary","isEntryWord", "bin", "end"};
    while (true)
    {
        for (int i = 0; task[i] != "end"; i++)
            std::cout << i + 1 << ')' << task[i] << '\n';
        std::cin >> z;
        switch (z)
        {
        case TASK::OUT_ARR: {
            std::string fail;
            std::cout << "How do you want call fail?\n";
            std::cin.ignore();
            std::getline(std::cin, fail);
            int** arr = new int* [10];
            for (int i = 0; i < 10; i++)
                arr[i] = new int[10];
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 10; j++)
                    arr[i][j] = i * 10 + j;
            outArr(fail, arr, 10, 10);
            break;
        }
        case TASK::OVERWRITING: {
            std::ofstream fout;
            fout.open("fail1.txt");
            int* arr = new int[15];
            for (int i = 0; i < 15; i++)
            {
                arr[i] = i;
                fout << arr[i] << ' ';
            }
            fout.close();
            overWriting(arr, 15, cond);
            break;
        }
        case TASK::NUMBER3: {
            number3();
            break;
        }
        case TASK::BREAKETS: {
            createBreakets();
            const char* const numbers[] = { "more.txt", "less.txt", "equaval.txt", "end" };
            for (int i = 0; numbers[i] != "end"; i++)
                std::cout << "fail " << numbers[i] << " : " << checkBreakets(numbers[i]) << '\n';
            break;
        }
        case TASK::VOCABLUARY: {
            std::cout << "Input text = ";
            outMap(createVoc());
            break;
        }
        case TASK::ISENTRY_WORD: {
            std::string text;
            std::cout << "Input text:\n";
            std::cin.ignore();
            std::getline(std::cin, text);
            std::ofstream fout;
            std::string file = "file6.txt";
            fout.open("file6.txt");
            fout << text;
            fout.close();

            std::string word;
            std::cout << "Input word:\n";
            std::cin >> word;
            (isEntryWord(file, word)) ? std::cout << "Have\n" : std::cout << "Haven't\n";
        }
        case TASK::BIN: {
            FILE *f;
            fopen_s(&f, "file7.txt", "wb");
            char str[] = "Hello world\nhello world\nhello..";
            for (int i = 0; i < 32; i++)
                fwrite(&str[i], sizeof(char), 1, f);
            fclose(f);

            system("pause");

            fopen_s(&f, "file7.txt", "rb");
            char a[33]{};
            fread(a, sizeof(char), 32, f);
            fclose(f);
            fopen_s(&f, "file7.txt", "wb");
            char XOR = a[0];
            for (int i = 1; i < 32; i++)
                XOR = XOR ^ a[i];
            int x = XOR;
            std::cout << XOR;
            fwrite(&x, sizeof(int) * 1, 1, f);
            for(int i = 0; i < 32; i++)
                fwrite(&a[i], sizeof(char), 1, f);
            fclose(f);

           
           

                    
        }
        }
    }
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
