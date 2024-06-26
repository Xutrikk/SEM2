#pragma once

#include <Windows.h>
#include <iostream>
#include<cstring>

#define DICTNAMEMAXSIZE 20	
#define DICTMAXSIZE 100	
#define ENTRYNAMEMAXSIZE 30 
#define THROW1 "Create: ������� ������ ����� �������"
#define THROW2 "Create: �������� ������ ������������� ������� �������"
#define THROW3 "AddEntry: ������������ �������"
#define THROW4 "AddEntry: ������������ ��������������"
#define THROW5 "GetEntry:  �� ������ �������"
#define THROW6 "DelEntry:  �� ������ �������"
#define THROW7 "UpdEntry:  �� ������ �������"
#define THROW8 "UpdEntry: ������������ ��������������"

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
	struct Entry { // ������� �������
		int		id;
		char	name[ENTRYNAMEMAXSIZE];
	};

	struct Instance {
		char name[DICTNAMEMAXSIZE];
		int maxsize;
		int size;
		Entry* dictionary[DICTMAXSIZE];
	};

	Instance Create( //������� �������
		char name[DICTNAMEMAXSIZE],// ��� ������� 
		int size // ������� ������� < DICTNAMEMAXSIZE
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

	void Print(Instance& d);		// ������ �������
	void Delete(Instance& d);	// ������� �������

}
#pragma once
