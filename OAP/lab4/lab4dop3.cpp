﻿#include <iostream>
#include <fstream>
#include <string>


using namespace std;

FILE* f;
// Объявление функций, которые будут реализованы ниже
void input(int size);
void output();
void find(string name);
// Определение структуры для представления информации о санатории
struct camp {
	string campName;
	string campPlace;
	string campType;
	int voucher;
};

void main() {
	setlocale(LC_ALL, "rus");
	for (;;) {
		cout << "1.Ввод нового санатория" << endl;
		cout << "2.Ввывод всей таблицы санаториев" << endl;
		cout << "3.Поиск санатория по названию" << endl;
		int a;
		cin >> a;
		switch (a) {
		case 1:
			input(1);
			break;
		case 2:
			output();
			break;
		case 3:
			cout << "Поиск путевок по названию" << endl;
			string name;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name);
			find(name);

		}
	}
}
// Функция для ввода данных о санатории
void input(int size) {
	camp buf;
	if (!fopen_s(&f, "base.bin", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cout << "Название санатория " << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, buf.campName);
			cout << "Место расположения: ";
			getline(cin, buf.campPlace);
			cout << "Лечебный профиль: ";
			getline(cin, buf.campType);
			cout << "Количество путевок: ";
			cin >> buf.voucher;
			fwrite(&buf, sizeof(camp), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
	}
	return;
}
// Функция для вывода данных о всех санаториях
void output() {
	camp buf;
	ifstream file("base.bin");
	while (file.read((char*)&buf, sizeof(buf))) {
		cout << "Название лагеря: " << buf.campName << "\t";
		cout << "Место лагеря: " << buf.campPlace << "\t";
		cout << "Профиль лечения: " << buf.campType << "\t\t";
		cout << "Количество путевок: " << buf.voucher << "\t" << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	}
}
// Функция для поиска санатория по названию
void find(string name) {
	camp buf;
	ifstream file("base.bin");
	while (file.read((char*)&buf, sizeof(buf))) {
		if (name == buf.campName) {
			cout << "Название лагеря: " << buf.campName << "\t";
			cout << "Место лагеря: " << buf.campPlace << "\t";
			cout << "Профиль лечения: " << buf.campType << "\t\t";
			cout << "Количество путевок: " << buf.voucher << "\t" << endl;
			cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
}