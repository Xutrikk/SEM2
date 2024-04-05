#include<iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int generateRandomNumber(int min, int max) {
	return min + rand() % (max - min + 1);
}
int* generateArray(int size, int min, int max) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = generateRandomNumber(min, max);
	}
	return arr;
}
void printArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	}
void BubbleSort(int* arr, int size){
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void InsertionSort(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		int buff = arr[i];
		int j = i - 1;
		for (; j >= 0 && arr[j] > buff; j--) {
			arr[j + 1] = arr[j];			
		}
		arr[j + 1] = buff;
	}
}
void SelectionSort(int* arr, int size) {
	int i = 0;
	while (i < size) {
		int pos = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[pos] > arr[j]) {
				pos = j;
			}
	    }
		int temp = arr[pos];
		arr[pos] = arr[i];
		arr[i] = temp;
		i++;
	}
}
void QuickSort(int* arr, int min, int max) {
	if (min < max) {
		int pivot = arr[(min + max) / 2];
		int i = min;
		int j = max;
		while (i <= j) {
			while (arr[i] < pivot) {
				i++;
			}
			while (arr[j] > pivot) {
				j--;
			}
			if (i <= j) {
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}
		QuickSort(arr, min, j);
		QuickSort(arr, i, max);
	}
}
	int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int min, max;
	cout << "Введите минимальное значение для генерации случайных чисел: ";
	cin >> min;
	cout << "Введите максимальное значение для генерации случайных чисел: ";
	cin >> max;
	if (max <= min) {
		cout << "Куда мы лезем боже.Максимальное значение должно быть больше минимального значения." << endl;
		return 1;
	}
	int N;
	cout << "Введите количество элементов массива: ";
	cin >> N;
	int* A = generateArray(N, min, max); 
	if (N < min || N > max) {
		cout << "Куда мы лезем боже.Количество элементов массива должно быть в диапазоне от " << min << " до " << max << "." << endl;
		return 1;
	}
	cout << "Исходный массив A: ";
	printArray(A, N);
	

	int* B = new int[N];
	int* C = new int[N];
	int* D = new int[N];
	int* E = new int[N];

	for (int i = 0; i < N; ++i) {
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
	}
	unsigned int start_time_bubble = clock();
	BubbleSort(B, N);
	unsigned int end_time_bubble = clock();
	unsigned int search_time_bubble = end_time_bubble - start_time_bubble;
	cout << "Отсортированный массив B: ";
	printArray(B, N);
	cout << "Время выполнения : " << search_time_bubble << " мс.\n\n\n" << endl;

	unsigned int start_time_insertion = clock();
	InsertionSort(C, N);
	unsigned int end_time_insertion = clock();
	unsigned int search_time_insertion = end_time_insertion - start_time_insertion;
	cout << "Отсортированный массив C: ";
	printArray(C, N);
	cout << "Время выполнения : " << search_time_insertion << " мс.\n\n\n" << endl;

	unsigned int start_time_selection = clock();
	SelectionSort(D, N);
	unsigned int end_time_selection = clock();
	unsigned int search_time_selection = end_time_selection - start_time_selection;
	cout << "Отсортированный массив D: ";
	printArray(D, N);
	cout << "Время выполнения : " << search_time_selection << " мс.\n\n\n" << endl;

	unsigned int start_time_quick = clock();
	QuickSort(E, 0, N - 1);
	unsigned int end_time_quick = clock();
	unsigned int search_time_quick = end_time_quick - start_time_quick;
	cout << "Отсортированный массив E: ";
	printArray(E, N);
	cout << "Время выполнения : " << search_time_quick << " мс.\n\n\n" << endl;
	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
	delete[] E;
	return 0;
	}
	
