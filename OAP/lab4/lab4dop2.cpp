#include <iostream>
#include <string>
#include <algorithm>
//Описать структуру с именем TRAIN, содержащую поля: названия пункта назначения, номер поезда, время отправления.
//Написать программу, выполняющую ввод с клавиатуры данных в массив, состоящий из восьми элементов типа TRAIN
//(записи должны быть размещены в алфавитном порядке по названиям пунктов назначения); 
//вывод на экран информации о поездах, отправляющихся после введенного с клавиатуры времени 
//(если таких поездов нет, то вывести сообщение об этом).
using namespace std;

// Определение структуры TRAIN, которая содержит информацию о поезде
struct TRAIN {
    string destination; 
    int number; 
    string departure_time;
};

// Функция для сравнения двух поездов по пункту назначения
bool compareByDestination(const TRAIN& a, const TRAIN& b) {
    return a.destination < b.destination; // Возвращает true, если пункт назначения поезда a предшествует пункту назначения поезда b
}

// Функция для сортировки массива поездов по пункту назначения
void sortTrains(TRAIN trains[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compareByDestination(trains[j], trains[j + 1])) {
                swap(trains[j], trains[j + 1]); // Меняем местами поезда, если пункт назначения поезда j предшествует пункту назначения поезда j+1
            }
        }
    }
}


int main() {
    setlocale(LC_ALL, "Russian"); 
    const int SIZE = 8; 
    TRAIN trains[SIZE]; // Создание массива из 8 элементов типа TRAIN

    // Ввод данных о поездах с клавиатуры
    for (int i = 0; i < SIZE; i++) {
        cout << "Введите пункт назначения, номер поезда и время отправления для поезда " << i + 1 << ": ";
        cin >> trains[i].destination >> trains[i].number >> trains[i].departure_time;
    }

    // Сортировка поездов по пункту назначения в алфавитном порядке
    sortTrains(trains, SIZE);

    string input_time; 
    cout << "Введите время: ";
    cin >> input_time;

    bool found = false; // Флаг, указывающий, найдены ли поезды, отправляющиеся после введенного времени

    // Поиск поездов, отправляющихся после введенного времени
    for (int i = 0; i < SIZE; i++) {
        if (trains[i].departure_time > input_time) {
            found = true;
            cout << "Поезд номер " << trains[i].number << " отправляется в " << trains[i].departure_time << " в направлении " << trains[i].destination << ".\n";
        }
    }

    
    if (!found) {
        cout << "Поездов, отправляющихся после введенного времени, не найдено.\n";
    }

    return 0; 
}
