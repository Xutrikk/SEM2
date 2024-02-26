#include<iostream>

using namespace std;
void guessNumber(int a, int b, int steps) {
	setlocale(LC_ALL, "Russian");
	int x = a + (b - a) / 2;
	if (a > b) {
		cout << "Ура, победа\n";
		cout << "Максимальное количество шагов бинарного поиска: " << steps << endl;
		return;
	}
	cout << "Я думаю это число:\n " << x << endl;
	cout << "1 - Вы угадали загаданное число\n";
	cout << "2 - Загаданное число больше\n";
	cout << "3 - Загаданное число меньше\n";
	string otvet;
	cin >> otvet;
	steps++;
	if (otvet == "1") {
		cout << "Ура,победа\n";
		cout << "Максимальное количество шагов бинарного поиска: " << steps << endl;
	}
	else if (otvet == "2") {
		guessNumber(x + 1, b, steps);
	}
	else if (otvet == "3") {
		guessNumber(a, x - 1, steps);
	}
}
int main() {
	int N;
	int steps = 0;
	setlocale(LC_ALL, "Russian");
	cout << "Введите N: \n";
	cin >> N;
	cout << "Загадайте число от 1 до N\n";
	guessNumber(1, N, steps);
	return 0;
}
