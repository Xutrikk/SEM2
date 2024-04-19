#pragma 
#include <cstring>
#include "stdafx.h"
#define DICTNAMEMAXSIZE 20 // максимальный размер имени словар€
#define DICTMAXSIZE 100 // максимальна€ емкость словар€
#define ENTRYNAMEMAXSIZE 30 // максимальна€ длина имени в словаре
#define THROW01 "Create: превышен размер имени словар€\n"
#define THROW02 "Create: превышен размер максимальной емкости словар€\n"
#define THROW03 "AddEntry: переполнение словар€\n"
#define THROW04 "AddEntry: дублирование идентификатора\n"
#define THROW05 "GetEntry: не найден элемент\n"
#define THROW06 "DelEntry: не найден элемент\n"
#define THROW07 "UpdEntry: не найден элемент\n"
#define THROW08 "UpdEntry: дублирование идентификатора\n"

namespace MyDictionary
{
	struct Entry
	{
		int id; // идентификатор(уникальный)
		char name[ENTRYNAMEMAXSIZE]; // символьна€ информаци€

	};
	struct Instance // экземпл€р словар€
	{
		char name[DICTNAMEMAXSIZE]; // наименование словар€
		int maxsize; // максимальна€ емкость словар€
		int size; // текущий размер словар€
		Entry* dictionary; // массив элемнтов словар€
	};
	Instance Create( // создать словарь
		const char name[DICTNAMEMAXSIZE], // им€ словар€
		int size // емкость словар€ < DICTNAMEMAXSIZE
	);
	void AddEntry( // добавить элемент словар€
		Instance& inst, // экземпл€р словар€
		Entry ed // элемент словар€
	);
	void DelEntry( // удалить элемент словар€
		Instance& inst, // экземпл€р словар€
		int id // идентификатор удал€емого элемента (уникальный)
	);
	void UpdEntry( // изменить элемент словар€
		Instance& inst, // экземпл€р словар€
		int id, // идентификатор удал€емого элемента (уникальный)
		Entry new_ed // новый элемент словар€
	);
	Entry GetEntry(
		Instance& inst, // экземпл€р словар€
		int id // идентификатор удал€емого элемента (уникальный)
	);
	void Print(Instance d); // печать словар€
	void Delete(Instance& d); // удалить словарь
}