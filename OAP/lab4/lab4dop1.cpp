#include<iostream>
#include<string>
using namespace std;
//Определить структуру для представления информации о сданных студентом экзаменах, содержащую поля: 
// ФИО студента, число экзаменов, полученные оценки.
//Определить функции для обработки отдельного объекта (например, для проверки, сданы ли все экзамены на 4 и 5). 
//Написать функцию для обработки массива структур.
//В результате обработки требуется вычислить характеристику успеваемости студентов,
//то есть отношение числа студентов, сдавших экзамены на 4 и 5, к общему числу студентов, в процентах.

// Определение структуры для представления информации о сданных студентом экзаменах
struct student {
	string fio; 
	int num_ex; 
	int* marks; 
};

// Функция для проверки, сданы ли все экзамены на 4 и 5
bool zachet(student a);

// Функция для вычисления характеристики успеваемости студентов
double prosent(student* a, int n);

void main() {
	setlocale(LC_ALL, "rus");
	student a[10]; 
	cout << "Введите количесвто студентов" << endl;
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "fio" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, a[i].fio); 
		cout << "Количество экзаменов" << endl;
		cin >> a[i].num_ex; 
		cout << "Оценки" << endl;
		a[i].marks = new int[a[i].num_ex]; // Выделение памяти под оценки
		for (int j = 0; j < a[i].num_ex; j++) {
			cin >> a[i].marks[j]; 
		}
	}
	int q; 
	cout << "Введите номер студента которого нужно проверить:" << endl;
	cin >> q;
	if (zachet(a[q-1]) == true) {
		cout << "Данный студент успешно закрыл сессию" << endl; 
	}
	else {
		cout << "Данный студент не сдал сессию" << endl; // Вывод сообщения, если студент не закрыл сессию
	}
	cout << "Процентное отношение отличников к общему количеству студентов:" << endl;
	cout << prosent(a, n); 
	cout << " процентов";
}

// Функция для проверки, сданы ли все экзамены на 4 и 5
bool zachet(student a) {
	int count = a.num_ex; 
	for (int j = 0; j < count; j++) {
		if (a.marks[j] < 4) 
			return false;		
	}
	return true; // Возвращаем true, если все экзамены сданы на 4 и 5
}

// Функция для вычисления характеристики успеваемости студентов
double prosent(student* a, int n) {
	double good = 0; 
	int all = 0; 
	for (int i = 0; i < n; i++) {
		bool flag = true; 
		int count = a[i].num_ex; 
		for (int j = 0; j < count; j++) {
			if (a[i].marks[j] < 4) { 
				flag = false; 
				break; 
			}
		}
		if (flag == true) { 
			good++; 
		}
	}
	double pros = (good / n) * 100; 
	return pros; 
}
