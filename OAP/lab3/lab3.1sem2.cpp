#include <fstream>
#include <iostream>
#include <stdio.h>

// Ввести с клавиатуры строку символов, состоящую из слов, разделенных пробелами, и записать ее в файл.
// Прочитать из файла данные и вывести все слова, которые содержат букву «х».

// Функция для записи введенной строки в файл
void fromFile(char s[]);

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    char buff[1000];  
    char str[1000];   
    int i, j, t;

    cout << "Введите строку : ";
    gets_s(str);  // Считываем входную строку от пользователя

    fromFile(str);  // Записываем входную строку 

    cout << endl;

    t = 0;
    j = 0;
    ifstream fin("f1.txt");  
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n"; 
    else
    {
        while (!fin.eof())  // Читаем слова из файла до конца файла
        {
            fin >> buff;  // Читаем слово из файла
            j = j + 1;
            for (i = 0; i < strlen(buff); i++)
            {
                if (buff[i] == 'x')  
                {
                    cout << buff << endl; 
                    break;
                }
                else
                    t = t + 1;
            }
        }
        if (t == j)
            cout << " Слов с буквой x нет";  
    }
    fin.close();  

    return 0;
}


void fromFile(char s[50])
{
    ofstream f("f1.txt");  

    if (f.fail())
    {
        cout << "\n Ошибка открытия файла";  
        exit(1);
    }
    else
        f << s;  
    f.close();  
}
