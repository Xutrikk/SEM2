#include <iostream>
#include <limits.h>
#include <float.h>

using namespace std;
int raz(int x, int y) { return x - y; };
int(*f) (int, int);

int main()
{
	setlocale(LC_CTYPE, "Russian");

	//объявление
	int n = 15, X = 9 + n, Y = 10 + n, Z = 11 + n;
	float S = 16.0;



	//4
	// bool(1 байт)
	bool tr = true;
	bool fal = false;
	//tr = 01; fal = 00;



	//5,6
	//char(1 байт)
	char let_eng = 'u';
	char let_ru = 'у';
	//eng = 75; ru = f3;



	//7,8
	// wchar_t(2 байта)
	wchar_t let_w_eng = L'H';
	wchar_t let_w_ru = L'X';
	//eng = 4800; ru =  5800;



	//9
	// short(unsigned short) (2 байта)
	short n_s_p = X; // DEC(24) -> HEX(18)
	short n_s_m = -X; // DEC(-24) ->HEX(E8)



	//10
	short min_s = 0x8000;
	short max_s = 0x7fff;
	//max_s = 32768, HEX(8000) ; min_s = -32767, HEX(7FFF)




	//11
	unsigned short min = 0x0;
	unsigned short max = 0xffff;
	//max = 65535, HEX(ffff); min = 0, HEX(0) 



	//12
	// int (4 байта)
	int n_int_p = Y;
	int n_int_m = -Y;
	// DEC(-25) -> BIN(10011001) -> BIN(11100110) -> HEX(e6) ; 
	// DEC(15) -> HEX(19)



	//13
	int min_i = 0x80000001; //DEC(-2147483647) -> HEX(80000001)
	int max_i = 0x7fffffff; //DEC(2147483647) -> HEX(7fffffff)



	//14
	unsigned int min_u_i = 0x0; //HEX(0)
	unsigned int max_u_i = 0xffffffff; //DEC(4294967295) -> HEX(ffffffff)



	//15
	// long(unsigned long) (4 байт)
	long n_long = Z; // DEC(26) -> HEX(1A)
	long n_long_m = -Z; // DEC(-26) -> BIN(10011010) -> BIN(11100101) -> HEX(e5)



	//16
	long min_l = 0x80000001; //DEC(-2147483647) -> HEX(80000001)
	long max_l = 0x7fffffff; //DEC(2147483647) -> HEX(7fffffff)



	//17
	unsigned long min_u_l = 0x0; // HEX(0)
	unsigned long max_u_l = 0xffffffff; //DEC(4294967295) -> HEX(ffffffff)



	//18
	float n_f_p = S; // 00 00 80 41
	float n_f_m = -S; // 00 00 80 c1


	float q1 = S / 0; // #INF
	cout << "q1 - " << q1 << endl;
	float q2 = -S / 0; // -#INF
	cout << "q2 - " << q2 << endl;
	double q3 = sqrt(-18.0); // -#IND
	cout << "q3 - " << q3 << endl;



	char c01 = 'c'; // один символ один байт
	wchar_t wc01 = L'c'; // один символ два байта
	short s01 = 18;
	int i01 = 180;
	float f01 = 18.1;
	double d01 = 18.0001;



	char* yc = &c01; //07 f3 54 1f ab 00 00 00
	wchar_t* ywc = &wc01; // 24 f3 54 1f ab 00 00 00
	short* ys = &s01; // 44 f3 54 1f ab 00 00 00
	int* yi = &i01; // 70 f3 54 1f ab 00 00 00
	float* yf = &f01; // 84 f3 54 1f ab 00 00 00
	double* yd = &d01; //  a8 f3 54 1f ab 00 00 00



	char* yc1 = yc + 3; // 07 f3 54 1f ab 00 00 00
	wchar_t* ywc1 = ywc + 3; //  2a f3 54 1f ab 00 00 00
	short* ys1 = ys + 3; //  4a f3 54 1f ab 00 00 00
	int* yi1 = yi + 3;  // 70 f3 54 1f ab 00 00 00
	float* yf1 = yf + 3; //  90 f3 54 1f ab 00 00 00
	double* yd1 = yd + 3; // c0 f3 54 1f ab 00 00 00



	f = raz;
	//&f(адрес) = c7 11 f1 00 ; f(знач) = e9 94 13 00
	int n21 = f(17, 13);

	cout << n21;

	return 0;

}