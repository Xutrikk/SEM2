#include <iostream>
using namespace std;
int S(int x) {
    if (x > 100) {
        return x + 10;
    }
    else {
        return S(x + 4);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int x;
    cout << "Введите x: ";
    cin >> x;
    cout << "S(x) = " << S(x) << endl;
    return 0;
}