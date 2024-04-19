#include <iostream>
using namespace std;
void printArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void Sort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int* tempArr = new int[size];
    int minIndex = 0;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            tempArr[i] = arr[size - minIndex - 1];
        }
        else {
            tempArr[i] = arr[minIndex++];
        }
    }
    for (int i = 0; i < size; i++) {
        arr[i] = tempArr[i];
    }

    delete[] tempArr;
}
int summa(int* arr, int size) {
    int sum = 0;
    for (int i= 0; i < size; i++) {
        if (i % 2 != 0) { 
            sum += arr[i - 1];
        }
    }
    return sum;
}
int main()
{
    setlocale(LC_ALL, "Russian");
	int kol;
	cout << "Введите количество товаров:\n";
	cin >> kol;
	if (kol > 9999) {
		cout << "Зачем это вообще проверять" << endl;
		return 0;
	}
	cout << "Изначальный порядок:"<< endl;
	int* arr = new int[kol];
	for (int i = 0; i < kol; i++) {
		arr[i] = rand() % 99 + 1;
		cout << arr[i] << " ";
	}
    cout << "\nХитрый кассир намутил:" << endl;
	Sort(arr, kol);
    printArray(arr, kol);
    int MaxCheck=summa(arr, kol);
    cout << "\nМаксимальная сумма чека:" << MaxCheck << endl;
	return 0;
}