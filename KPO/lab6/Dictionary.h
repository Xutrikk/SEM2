#pragma once

#include <Windows.h>
#include <iostream>
#include<cstring>

#define DICTNAMEMAXSIZE 20	
#define DICTMAXSIZE 100	
#define ENTRYNAMEMAXSIZE 30 
#define THROW1 "Create: превшен размер имени словаря"
#define THROW2 "Create: превышен размер максимального емкости словаря"
#define THROW3 "AddEntry: переполнение словаря"
#define THROW4 "AddEntry: дублирование индетификатора"
#define THROW5 "GetEntry:  не найден элемент"
#define THROW6 "DelEntry:  не найден элемент"
#define THROW7 "UpdEntry:  не найден элемент"
#define THROW8 "UpdEntry: дублирование индетификатора"

#define TEST_CREATE_01
//#define TEST_CREATE_02
//#define TEST_ADDENTRY_03
//#define TEST_ADDENTRY_04 
//#define TEST_GETENTRY_05
//#define TEST_GETENTRY_06
//#define TEST_UPDENTRY_07
//#define TEST_UPDENTRY_08
//#define TEST_DICTIONARY

namespace Dictionary {
	struct Entry { // элемент словаря
		int		id;
		char	name[ENTRYNAMEMAXSIZE];
	};

	struct Instance {
		char name[DICTNAMEMAXSIZE];
		int maxsize;
		int size;
		Entry* dictionary[DICTMAXSIZE];
	};

	Instance Create( //создать словарь
		char name[DICTNAMEMAXSIZE],// имя словаря 
		int size // емкость словаря < DICTNAMEMAXSIZE
	);

	void AddEntry(
		Instance& inst,
		Entry ed);

	void DelEntry(
		Instance& inst,
		int id
	);

	void UpdEntry(
		Instance& inst,
		int id,
		Entry new_ed
	);

	Entry GetEntry(
		Instance& inst,
		int id
	);

	void Print(Instance& d);		// Печать словаря
	void Delete(Instance& d);	// Удалить словарь

}
#pragma once
