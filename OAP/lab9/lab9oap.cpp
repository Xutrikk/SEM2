#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
const char FOUND1[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮйцукенгшщзхъфывапролджэячсмитьбю";
const char FOUND2[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNMЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮйцукенгшщзхъфывапролджэячсмитьбю";
const char FOUND[] = "0123456789";
const char FOUND3[] = "0123456789-";
using namespace std;

const unsigned int NAME_SIZE = 256;
const unsigned int CITY_SIZE = 256;

struct Address
{
	string name;
	string city;
	int ch;
	Address* next;
	Address* prev;
};

void insert(Address* e, Address** phead, Address** plast);
Address* setElement();
void outputList(Address** phead, Address** plast);
void delet(string name, Address** phead, Address** plast);
void find(string name, Address** phead);
void writeToFile(Address** phead);
void readFromFile(Address** phead, Address** plast);
Address* InsertEnd();

int main()
{
	string s;  int c;
	string dname;
	string fname;
	setlocale(LC_CTYPE, "Rus");
	Address* head = NULL;
	Address* last = NULL;
	short choose = 0;
	while (choose != 5)
	{

		cout << "Выберите действие:\n1 — ввод элемента;\n2 — вывод списка;\n3 — удаление элемента;\n4 — поиск элемента;"
			"\n5 — запись в файл;\n6 — считывание из файла;\n7 — добавление в конец списка всех элементов некоторого списка L;\n8 — выход из программы.\n";
		do
		{
			getline(cin, s);
		} while (s.find_first_not_of(FOUND) != string::npos);

		c = stoi(s);


		switch (c)
		{
		case 1:
			insert(setElement(), &head, &last);
			break;
		case 2:
			outputList(&head, &last);
			break;
		case 3:
			do
			{
				cout << "Введите имя: ";
				getline(cin, dname);
				cin.ignore(cin.rdbuf()->in_avail());
				cin.clear();
			} while (dname.find_first_not_of(FOUND2) != string::npos);
			delet(dname, &head, &last);
			break;
		case 4:
			do
			{
				cout << "Введите имя: ";
				getline(cin, fname);
				cin.ignore(cin.rdbuf()->in_avail());
				cin.clear();
			} while (fname.find_first_not_of(FOUND2) != string::npos);
			find(fname, &head);
			break;
		case 5:
			writeToFile(&head);
			break;
		case 6:


			readFromFile(&head, &last);
			break;
		case 7:
			insert(InsertEnd(), &head, &last);
			break;
		case 8:
			cout << "Бай Бай\n";
			exit(0);
		}
	}
}

void insert(Address* e, Address** phead, Address** plast)
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}

Address* setElement()
{
	string cho, cho1, cho2;
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти.\n";
		return NULL;
	}

	do
	{
		cout << "Введите имя: ";
		getline(cin, cho1);
		cin.ignore(cin.rdbuf()->in_avail());
		cin.clear();
	} while (cho1.find_first_not_of(FOUND2) != string::npos);
	temp->name = cho1;

	do
	{
		cout << "Введите город: ";
		getline(cin, cho2);
		cin.ignore(cin.rdbuf()->in_avail());
		cin.clear();
	} while (cho1.find_first_not_of(FOUND1) != string::npos);
	temp->city = cho2;


	do
	{
		cout << "Введите число: ";
		getline(cin, cho);
		cin.ignore(cin.rdbuf()->in_avail());
		cin.clear();
	} while (cho.find_first_not_of(FOUND3) != string::npos);

	temp->ch = stoi(cho);

	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void outputList(Address** phead, Address** plast)
{
	Address* t = *phead;
	while (t)
	{
		cout << "Имя: " << t->name << ' ' << "Город: " << t->city << ' ' << "Число: " << t->ch << '\n';
		t = t->next;
	}
	cout << endl;
}

void delet(string name, Address** phead, Address** plast)
{
	struct Address* t = *phead;
	while (t)
	{
		if (name == t->name)  break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено.\n" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален.\n" << endl;
	}
}

void find(string name, Address** phead)
{
	Address* t = *phead;
	while (t)
	{
		if (name == t->name) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено.\n" << endl;
	else
		cout << t->name << ' ' << t->city << ' ' << t->ch << endl;
}

void writeToFile(Address** phead) //Запись в файл
{
	struct Address* t = *phead;
	ofstream file1("file.txt");
	if (file1.fail())
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		file1 << t->name << "\t" << t->city << "\t" << t->ch << '\t';
		file1 << endl;
		t = t->next;
	}
	file1.close();
}

void readFromFile(Address** phead, Address** plast)
{

	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;


	string buf;
	string word;
	ifstream file1("file.txt");
	if (file1.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (!file1.eof())
	{
		while (getline(file1, buf))
		{
			int j = 0;
			struct Address* t = new Address;

			for (int i = 0; i < buf.length(); i++)
			{
				if (buf[i] != '\t')
				{
					word += buf[i];

				}
				else
				{
					switch (j)
					{
					case 0:
						t->name = word;
						word.clear();
						break;
					case 1:
						t->city = word;
						word.clear();
						break;
					case 2:
						t->ch = stoi(word);
						word.clear();
					}
					j++;
				}
			}

			if (j == 3)
			{
				Address* p = *plast;
				if (*plast == NULL)
				{
					t->next = NULL;
					t->prev = NULL;
					*plast = t;
					*phead = t;
				}
				else
				{
					p->next = t;
					t->next = NULL;
					t->prev = p;
					*plast = t;
				}
			}

		}

	}

	file1.close();
}

void deleteX(Address** phead, Address** plast)
{
	string cho;
	int x;
	do
	{
		cout << "Введите число x: ";
		getline(cin, cho);
		cin.ignore(cin.rdbuf()->in_avail());
		cin.clear();
	} while (cho.find_first_not_of(FOUND3) != string::npos);
	x = stoi(cho);
	struct Address* t = *phead;
	while (t)
	{
		if (x == t->ch)  break;
		t = t->next;
	}
	if (!t)
		cerr << "Элемент не найден" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}

Address* InsertEnd()
{
	Address* L1 = new Address{ "оаип", "лаба99",245, nullptr, nullptr };

	Address* head = nullptr;
	Address* last = nullptr;
	Address* p = L1;
	while (p != nullptr)
	{
		Address* e = new Address{ p->name, p->city, p->ch, nullptr, nullptr };
		insert(e, &head, &last);
		p = p->next;
	}

	return head;
}